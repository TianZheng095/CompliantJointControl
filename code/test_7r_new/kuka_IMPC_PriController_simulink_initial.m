% clc; close all; clear; 

%% Basic Parameters
N = 3;
Ts = 0.001;


% level 1: [x y z] of EE
k_p_lev1 = 10; 
k_v_lev1 = 1;

k_e_lev1 = [k_p_lev1;k_v_lev1];

Q_const_lev1 = 30; 
R_const_lev1 = 4;

M_factor = 0.3;
D_factor = 0.5;



%% Load rigid body model of manipulator
% kuka = loadrobot('kukaiiwa14','Gravity',[0 0 -9.81]);
% % kuka = loadrobot('kukaiiwa14','Gravity',[0 0 0]);
% 
% kuka.DataFormat = 'column';
% showdetails(kuka);


%% Initial configutation of manipulator 
const_Degree2Rad = pi/180;

q_ini = 0;
q_ini = const_Degree2Rad*q_ini;
qd_ini = 0;
qd_ini = const_Degree2Rad*qd_ini;
q_bar_ini = [q_ini;qd_ini];

theta_ini = 0;
theta_ini = const_Degree2Rad*theta_ini;


% initial torque due to gravitz
% gravity_tau_ini = gravityTorque(kuka,q_ini);
% tau_ini = gravity_tau_ini;
% qdd_ini = forwardDynamics(kuka,q_ini,qd_ini,tau_ini);
tau_ini = 0;


M_bar_inv  = inv(M_factor*exJoint.I_l);

D_bar_inv = inv(D_factor*(exJoint.I_m+exJoint.I_g));
K = exJoint.k_b;



%% Reference Trajectory
n_max_ref = 4000;
n_ini_stop = 0;
T_run = Ts*(n_max_ref+n_ini_stop-5);
plot_ref = 0;

% % level 1: [x y z] of EE
% r_ref_lev1 = 0.1; 
q_max_ref = 90; 
q_max_ref = const_Degree2Rad*q_max_ref;


% 
% [Xr,Xd_r_lev1] = Get_X_ref(kuka,Ts,q_ini,Transform_ee_ini, n_ini_stop,n_max_ref, k_e_lev1,r_ref_lev1,angle_max_lev1, plot_ref);
% Xprime_r_lev1 = Xr{1,1}; X_r_lev1 = Xr{1,2};


Xr = Get_q_ref(Ts,q_ini, n_ini_stop,n_max_ref, k_e_lev1,q_max_ref);
Xprime_r_lev1 = Xr{1,1}; X_r_lev1 = Xr{1,2}; Xd_r_lev1 = Xr{1,3};

%% Inequality constraints
% joint angle constraints
q_max = 100; 
q_max = const_Degree2Rad*q_max;
q_min = -10; 
q_min = const_Degree2Rad*q_min;

% joint velocity constraints
qd_max_amp = 200;
qd_max = const_Degree2Rad*qd_max_amp;
qd_min = -qd_max;

% joint toruqe constraints


% tau_max = [176;176;110;110;110;40;40];
% tau_max = 120*ones(7,1);
% tau_max = [100;100;80;50;50;10;10];
tau_max = 100;
tau_min = -tau_max;

dtau_max = 10;
dtau_min = -dtau_max;

tau_max_bar = repmat(tau_max,N,1);
tau_min_bar = repmat(tau_min,N,1);

dtau_max_bar = repmat(dtau_max,N,1);
dtau_min_bar = repmat(dtau_min,N,1);



%% Parameters used for QP
% level 1: [x y z] of EE
A_11_lev1 = [  1  Ts  0; 
               0  2   M_bar_inv*K*Ts*Ts;
               0  0   2]; 
A_12_lev1 = [0,0,0;0,-1,0;0,0,-1];
A1_X_lev1 = [A_11_lev1   A_12_lev1;
                eye(3)    zeros(3)];
B11_dtau_lev1 = [0;0;D_bar_inv*Ts];
B1_dtau_lev1 = [B11_dtau_lev1;0;0;0];
    
A1_X_bar_lev1 = Formulate_N_PowerMatVector(N, A1_X_lev1);

B1_dtau_bar_lev1 = Formulate_N_RecurMat(N, A1_X_lev1,B1_dtau_lev1);



P_X2x_prime_lev1 = Get_P_X2x_prime_lev1(k_e_lev1);
U_lev1 = P_X2x_prime_lev1'*Q_const_lev1*P_X2x_prime_lev1;
L_lev1 = Formulate_N_BlkdiagMat(N, U_lev1);
K_lev1 = Formulate_N_BlkdiagMat(N, Q_const_lev1*P_X2x_prime_lev1');

H = 2*R_const_lev1*eye(N)+2*B1_dtau_bar_lev1'*L_lev1*B1_dtau_bar_lev1;
H_QP_lev1 = reshape(H,N*N,1); 




%% Parameters used for Inequality

% Matrix representation of inequality constraints
% L1 = [eye(7) zeros(7,21)];
% L2 = [zeros(7) eye(7) zeros(7,14)];
% 
% L1_bar = Formulate_N_BlkdiagMat(N, L1); 
% L2_bar = Formulate_N_BlkdiagMat(N, L2);
% 
% L1_tilde = L1_bar*A2_Y_bar; 
% L2_tilde = L2_bar*A2_Y_bar; 
% W1 = L1_bar*B2_dtau_bar;
% W2 = L2_bar*B2_dtau_bar;

diagIOO = Formulate_N_BlkdiagMat(N, [1 0 0 0 0 0]);
L1_tilde = diagIOO*A1_X_bar_lev1;
W1 = diagIOO*B1_dtau_bar_lev1;
diagOIO = Formulate_N_BlkdiagMat(N, [0 1 0 0 0 0]);
L2_tilde = diagOIO*A1_X_bar_lev1;
W2 = diagOIO*B1_dtau_bar_lev1;




lb_QP = dtau_min_bar;
ub_QP = dtau_max_bar;

% with qd constraints
I_bar = kron(tril(ones(N)),eye(1));
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
theta_sim_ini = theta_ini;
q_bar_sim_ini = q_bar_ini;
x1_bar_sim_ini = [q_bar_ini;
                  theta_ini];



%%% End of file


















