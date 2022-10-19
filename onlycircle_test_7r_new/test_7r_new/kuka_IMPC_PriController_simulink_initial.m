% clc; close all; clear; 

%% Basic Parameters
N = 3;
Ts = 0.001;

Fe = 0;
% level 1: [x y z] of EE
k_p_lev1 = 100; 
k_v_lev1 = 1;
% k_a_lev1 = 1;
k_e_lev1 = [k_p_lev1;k_v_lev1];

Q_const_lev1 = 300; 
R_const_lev1 = 40;

M_factor = 0.3;




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

% M_diag = diag(massMatrix(kuka,q_ini));
M_diag = 10;
M_bar_inv  = inv(M_factor*diag(M_diag));

D_bar_inv = 10;
K = 5;

% load('g_bar.mat', 'g_bar');
% M_diag = g_bar;
% M_bar_inv  = 1*diag([M_diag{1};M_diag{2};M_diag{3};M_diag{4};M_diag{5};M_diag{6};M_diag{7}]);
% M_bar_inv = diag([1/0.1;1/0.21;1/0.033;1/0.042;1/0.001;1/0.001;1/0.0003]);
% M_bar_inv = 30*eye(7);
% M_bar_inv = diag([rand*5+5;rand*3.5+1.3;rand*20.4+9.9;rand*16.2+7.6;rand*913+87;rand*786+214;rand*2283+1050]);
% M_bar_inv = diag([1/0.1;1/0.21;1/0.033;1/0.042;1/0.001;1/0.001;1/0.0003]);


% x_ee_ini = q2x(kuka,q_ini,'iiwa_link_ee_kuka');
% eul_ee_ini = q2eul(kuka,q_ini,'iiwa_link_ee_kuka');
% Transform_ee_ini = getTransform(kuka,q_ini,'iiwa_link_ee_kuka');

% Nominal state model of Y(k) = [q_bar(k);q_bar(k-1)]
% A_21 = [eye(7)   Ts*eye(7); 
%         zeros(7)  2*eye(7)];
% A_22 = blkdiag(zeros(7),-eye(7));
% A2_Y = [A_21         A_22;
%         eye(14) zeros(14)];
% B2_dtau = [    zeros(7);
%            Ts*M_bar_inv;
%             zeros(14,7)];
%          
% A2_Y_bar = Formulate_N_PowerMatVector(N, A2_Y);
% B2_dtau_bar = Formulate_N_RecurMat(N, A2_Y,B2_dtau);


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
Xprime_r_lev1 = Xr{1,1}; X_r_lev1 = Xr{1,2};

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


















