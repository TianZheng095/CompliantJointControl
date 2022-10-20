clc; close all; clear; 

%% Basic Parameters
N = 3;
Ts = 0.001;

% level 1: [x y z] of EE
k_p_lev1 = 300; 
k_v_lev1 = 30;
k_e_lev1 = [k_p_lev1;k_v_lev1];

Q_const_lev1 = 200; 
R_const_lev1 = 10;

% level 2: q3 q4
k_p_lev2 = 300; 
k_v_lev2 = 30;
k_e_lev2 = [k_p_lev2;k_v_lev2];

Q_const_lev2 = 200; 
R_const_lev2 = 10;

% level 3: q1 q5 or [x y] of joint 3
k_p_lev3 = 300; 
k_v_lev3 = 30;
k_e_lev3 = [k_p_lev2;k_v_lev2];

Q_const_lev3 = 200; 
R_const_lev3 = 10;


%% Load rigid body model of manipulator
kuka = loadrobot('kukaiiwa14','Gravity',[0 0 -9.81]);
% kuka = loadrobot('kukaiiwa14','Gravity',[0 0 0]);
kuka.DataFormat = 'column';
% showdetails(kuka);


%% Initial configutation of manipulator 
const_Degree2Rad = pi/180;

q_ini = [0];
q_ini = const_Degree2Rad*q_ini;


qd_ini = zeros(1); 
q_bar_ini = [q_ini;qd_ini];

% initial torque due to gravitz
gravity_tau_ini = gravityTorque(kuka,q_ini);
tau_ini = gravity_tau_ini;
% tau_ini = zeros(7,1);
qdd_ini = forwardDynamics(kuka,q_ini,qd_ini,tau_ini);

M_diag = diag(massMatrix(kuka,q_ini));
M_bar_inv  = 18*inv(diag(M_diag));
% M_bar_inv = 30*eye(7);

x_ee_ini = q2x(kuka,q_ini,'iiwa_link_ee_kuka');
eul_ee_ini = q2eul(kuka,q_ini,'iiwa_link_ee_kuka');
Transform_ee_ini = getTransform(kuka,q_ini,'iiwa_link_ee_kuka');

% Nominal state model of Y(k) = [q_bar(k);q_bar(k-1)]
A_21 = [eye(7)   Ts*eye(7); 
        zeros(7)  2*eye(7)];
A_22 = blkdiag(zeros(7),-eye(7));
A2_Y = [A_21         A_22;
        eye(14) zeros(14)];
B2_dtau = [    zeros(7);
           Ts*M_bar_inv;
            zeros(14,7)];
         
A2_Y_bar = Formulate_N_PowerMatVector(N, A2_Y);
B2_dtau_bar = Formulate_N_RecurMat(N, A2_Y,B2_dtau);


%% Reference Trajectory
n_max_ref = 4000;
n_ini_stop = 0;
T_run = Ts*(n_max_ref+n_ini_stop-5);
plot_ref = 0;

% level 1: [x y z] of EE
r_ref_lev1 = 0.1; 
angle_max_lev1 = 360; 
angle_max_lev1 = const_Degree2Rad*angle_max_lev1;

% level 3: q1 
amp_ref_lev3 = 90; 
amp_ref_lev3 = const_Degree2Rad*amp_ref_lev3;
omg_ref_lev3 = 2*pi/(Ts*n_max_ref);

Xr = Get_X_ref(kuka,Ts,q_ini,Transform_ee_ini, n_ini_stop,n_max_ref, k_e_lev1,r_ref_lev1,angle_max_lev1, k_e_lev2, k_e_lev3,amp_ref_lev3,omg_ref_lev3, plot_ref);
Xprime_r_lev1 = Xr{1,1}; X_r_lev1 = Xr{1,2};
Xprime_r_lev2 = Xr{2,1}; X_r_lev2 = Xr{2,2};
Xprime_r_lev3 = Xr{3,1}; X_r_lev3 = Xr{3,2};


%% Inequality constraints
% joint angle constraints
q_max = 100; 
q_min = -20;
q_max = const_Degree2Rad*q_max;
q_min = const_Degree2Rad*q_min;


% joint velocity constraints
qd_max_amp = 500;
qd_max = const_Degree2Rad*qd_max_amp*ones(7,1);
qd_min = -qd_max;


% joint toruqe constraints
I_bar = kron(tril(ones(N)),eye(7));

tau_max = [176;176;110;110;110;40;40];
% tau_max = 120*ones(7,1);
tau_min = -tau_max;

dtau_max = tau_max/2;
dtau_min = -dtau_max;

tau_max_bar = repmat(tau_max,N,1);
tau_min_bar = repmat(tau_min,N,1);

dtau_max_bar = repmat(dtau_max,N,1);
dtau_min_bar = repmat(dtau_min,N,1);

% Matrix representation of inequality constraints
L1 = [eye(7) zeros(7,21)];
L2 = [zeros(7) eye(7) zeros(7,14)];

L1_bar = Formulate_N_BlkdiagMat(N, L1); 
L2_bar = Formulate_N_BlkdiagMat(N, L2);

L1_tilde = L1_bar*A2_Y_bar; 
L2_tilde = L2_bar*A2_Y_bar; 
W1 = L1_bar*B2_dtau_bar;
W2 = L2_bar*B2_dtau_bar;


%% Parameters used for QP
% level 1: [x y z] of EE
A_11_lev1 = [    eye(3) Ts*eye(3) zeros(3); 
               zeros(3)  2*eye(3) zeros(3); 
             zeros(3,6)             eye(3)]; 
A_12_lev1 = blkdiag(zeros(3),-eye(3),zeros(3));
A1_X_lev1 = [A_11_lev1   A_12_lev1;
                eye(9)    zeros(9)];
    
A1_X_bar_lev1 = Formulate_N_PowerMatVector(N, A1_X_lev1);

P_X2x_prime_lev1 = Get_P_X2x_prime_lev1(k_e_lev1);
U_lev1 = P_X2x_prime_lev1'*Q_const_lev1*P_X2x_prime_lev1;
L_lev1 = Formulate_N_BlkdiagMat(N, U_lev1);
K_lev1 = Formulate_N_BlkdiagMat(N, Q_const_lev1*P_X2x_prime_lev1');


% level 2: [alpha beta gamma] of EE
A_11_lev2 = [    eye(3) Ts*eye(3) zeros(3); 
               zeros(3)  2*eye(3) zeros(3); 
             zeros(3,6)             eye(3)]; 
A_12_lev2 = blkdiag(zeros(3),-eye(3),zeros(3));
A1_X_lev2 = [A_11_lev2  A_12_lev2;
                eye(9)   zeros(9)];
    
A1_X_bar_lev2 = Formulate_N_PowerMatVector(N, A1_X_lev2);

P_X2x_prime_lev2 = Get_P_X2x_prime_lev2(k_e_lev2);
U_lev2 = P_X2x_prime_lev2'*Q_const_lev2*P_X2x_prime_lev2;
L_lev2 = Formulate_N_BlkdiagMat(N, U_lev2);
K_lev2 = Formulate_N_BlkdiagMat(N, Q_const_lev2*P_X2x_prime_lev2');


% level 3: q1
J_lev3 = [1 0 0 0 0 0 0];

A_11_lev3 = [1 Ts  0; 
             0  2  0; 
             0  0  1]; 
A_12_lev3 = diag([0;-1;0]);
A1_X_lev3 = [A_11_lev3  A_12_lev3;
                eye(3)   zeros(3)];
B1_dtau_lev3 =  [         zeros(1,7);
                 Ts*J_lev3*M_bar_inv;
                    J_lev3*M_bar_inv;
                          zeros(3,7)];     
        
A1_X_bar_lev3 = Formulate_N_PowerMatVector(N, A1_X_lev3);
B1_dtau_bar_lev3 = Formulate_N_RecurMat(N, A1_X_lev3,B1_dtau_lev3);

P_X2x_prime_lev3 = Get_P_X2x_prime_lev3(k_e_lev3);
U_lev3 = P_X2x_prime_lev3'*Q_const_lev3*P_X2x_prime_lev3;
L_lev3 = Formulate_N_BlkdiagMat(N, U_lev3);
K_lev3 = Formulate_N_BlkdiagMat(N, Q_const_lev3*P_X2x_prime_lev3');

H_lev3 = 2*R_const_lev3*eye(7*N)+2*B1_dtau_bar_lev3'*L_lev3*B1_dtau_bar_lev3;
H_QP_lev3 = reshape(H_lev3,7*N*7*N,1);


%% Parameters used for Inequality
lb_QP = dtau_min_bar;
ub_QP = dtau_max_bar;

% with qd constraints
[m,n]=size([W1;W2;I_bar]);
A_QP = reshape([W1;W2;I_bar]',m*n,1);

lbA_QP_ini = [ repmat(q_min,N,1);
              repmat(qd_min,N,1);
                     tau_min_bar];
                 
ubA_QP_ini = [ repmat(q_max,N,1);
              repmat(qd_max,N,1);
                     tau_max_bar];
                 
% % without qd constraints
% [m,n]=size([W1;I_bar]);
% A_QP = reshape([W1;I_bar]',m*n,1);
% lbA_QP_ini = [ repmat(q_min,N,1);
%                      tau_min_bar];
% ubA_QP_ini = [ repmat(q_max,N,1);
%                      tau_max_bar];


%% Initialization for simulink
tau_sim_ini = tau_ini;
q_sim_ini = q_ini;
q_bar_sim_ini = q_bar_ini;
x1_bar_sim_ini = [x_ee_ini;
                  zeros(6,1)];
x2_bar_sim_ini = [eul_ee_ini;
                  zeros(6,1)];         
x3_bar_sim_ini = [  q_ini(1);
                   qd_ini(1);
                  qdd_ini(1)];


%%% End of file


















