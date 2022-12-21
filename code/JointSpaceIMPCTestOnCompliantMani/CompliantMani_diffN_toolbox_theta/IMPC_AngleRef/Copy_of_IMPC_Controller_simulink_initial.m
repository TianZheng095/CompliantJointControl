% clc; close all; clear; 

%% Basic Parameters
N = 10;
% Ts = 0.001; 


% M_bar = 1;
% M_bar_inv = inv(M_bar);
% K_b = 100;
% D_coe = 1;
% D_bar = D_coe*1;
% D_bar_inv = inv(D_bar);

syms Ts D_bar M_bar D_bar_inv M_bar_inv K_b;
syms Q_const R_const Kp;




% Q_const = 50;
% R_const = 0.1;
% Kp = 20;





%% Initial set of manipulator
q_ini = deg2rad(0);
qd_ini = 0; 
q_bar_ini = [q_ini;qd_ini];

tau_ini = 0;  


%% Reference Trajectory
plot_ref = 1;

amp_max = pi/2;
n_ref_2pi = 5000;
n_ref_times = 5;
n_ini_stop = 5000;

Xr = Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref);


%% Parameters used for QP
% Nominal state model 
A1_a22 = 2-M_bar_inv*K_b*Ts*Ts;
A1 = [1    Ts            0;
      0   A1_a22   M_bar_inv*K_b*Ts*Ts;
      0    0             2];
A2 = [0    0    0;
      0   -1    0;
      0    0   -1];
B1 = [0;
      0;
      D_bar_inv*Ts];
  
A = [    A1       A2;
     eye(3) zeros(3)];
B = [        B1;
     zeros(3,1)];

A_tilde = Formulate_N_PowerMatVector(N, A);%6Nx6
B_tilde = Formulate_N_RecurMat(N, A,B);%6NxN
R_tilde = Formulate_N_BlkdiagMat(N, R_const);%NxN

K_bar = [Kp 0 0 0 0 0;0 1 0 0 0 0];%2x6
Kd_bar = [Kp 0;0 1];%2x2

U_bar = K_bar'*Q_const*K_bar;%6x6
Q_tilde = Formulate_N_BlkdiagMat(N, U_bar);%6Nx6N

Ud_bar = Kd_bar'*Q_const*K_bar;%2x6
QB_tilde = Formulate_N_BlkdiagMat(N, Ud_bar)*B_tilde;%2Nx6N * 6NxN = 2NxN
AQB_tilde = A_tilde'*Q_tilde*B_tilde;%6xN


H = R_tilde+B_tilde'*Q_tilde*B_tilde;%NxN


% %%delta_tau_ref
% mm = M_bar*(1/(K_b*Ts*Ts));
% dd = D_bar*(1/Ts);
% delta_tau_ref_total = [];
% for j = 3:29996
%      
%     theta_r_k_1 = mm*(Xr(2,j+2)-(2-1/mm)*Xr(2,j+1)+Xr(2,j));
%     theta_r_k_0 = mm*(Xr(2,j+1)-(2-1/mm)*Xr(2,j)+Xr(2,j-1));
%     theta_r_k__1 = mm*(Xr(2,j)-(2-1/mm)*Xr(2,j-1)+Xr(2,j-2));
% 
%     delta_tau_ref = dd*(theta_r_k_1-2*theta_r_k_0+theta_r_k__1);
%     delta_tau_ref_total = [delta_tau_ref_total;
%                             delta_tau_ref];
%           
% end
% 
% delta_tau_ref_total=[0;0;0;delta_tau_ref_total];%one more 0 at beginning for timestamp t=0
% delta_tau_ref_total(5001:5003)=[0;0;0];

%% Inequality constraints
% joint angle constraints
q1_max = deg2rad(114.59); 
% q1_max = deg2rad(63.03); 


q_max = q1_max;
q_min = -q_max;

% joint velocity constraints
qd1_max = deg2rad(114.59); 
% qd1_max = deg2rad(45.84); 


qd_max = qd1_max;
qd_min = -qd_max;

% joint toruqe constraints
I_bar = kron(tril(ones(N)),1);%NxN

tau_max = 200;%50 is too small
tau_min = -tau_max;
dtau_max = 100;
dtau_min = -dtau_max;

tau_max_bar = tau_max*ones((N),1);
tau_min_bar = tau_min*ones((N),1);
dtau_max_bar = dtau_max*ones((N),1);
dtau_min_bar = dtau_min*ones((N),1);

% Matrix representation of inequality constraints
L1 = [eye(1) zeros(1,5)];
L2 = [zeros(1,1) eye(1) zeros(1,4)];

L1_bar = Formulate_N_BlkdiagMat(N, L1); %Nx6N
L2_bar = Formulate_N_BlkdiagMat(N, L2); %Nx6N

L1_tilde = L1_bar*A_tilde; %Nx6
L2_tilde = L2_bar*A_tilde; %Nx6
W1 = L1_bar*B_tilde;%NxN
W2 = L2_bar*B_tilde;%NxN


%% Parameters used for qpOASES
% H
H_QP = reshape(H,((N))^2,1);

% lb & ub
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
                 
%% Parameters used for manipulator
% B_mani = Ts*[0;
%              0;
%              0;
%              D_bar_inv];
B_mani = [0;
          0;
          0;
          D_bar_inv];
% g = 9.81;
% % L = exJoint.len/100/2;
% L = 1;
% m = 1;
% 
% a21 = -(m*g*L)/M_bar-K_b/M_bar;
% a23 = K_b/M_bar;
% a41 = K_b/D_bar;
% a43 = -K_b/D_bar;
% % A_mani = eye(4)+Ts*[0     1     0     0;
% %                     a21   0     a23   0;
% %                     0     0     0     1;
% %                     a41   0     a43   0];
% A_mani = [0     1     0     0;
%           a21   0     a23   0;
%           0     0     0     1;
%           a41   0     a43   0];

%% Initialization for simulink
tau_sim_ini = 0;
q_sim_ini = q_ini;
q_bar_sim_ini = q_bar_ini;
theta_sim_ini = q_ini;
X_bar_sim_ini = [q_bar_sim_ini;theta_sim_ini];

T_run = Ts*(n_ini_stop+n_ref_times*n_ref_2pi-N-5);



%%% End of file


















