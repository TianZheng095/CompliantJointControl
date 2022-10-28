% clc; close all; clear; 

%% Basic Parameters
N = 10;
Ts = 0.001; 
% Inertial = 0.01*exJoint.I_l;
Inertial = 1;
M_bar = Inertial;
Inertial_inv = inv(Inertial);
M_bar_inv = Inertial_inv;
% K_b = exJoint.k_b;
K_b = 100;
% D_bar = exJoint.I_m+exJoint.I_g;
% D_bar = 0.01*D_bar;
D_bar = 1;
D_bar_inv = inv(D_bar);




Q_const = 50;
% R = 0.005;
R = 0.1;
Kp = 10;




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
A1 = [eye(1)   Ts*eye(1)   0;
      zeros(1)  2*eye(1)   M_bar_inv*K_b*Ts*Ts;
      zeros(1)  zeros(1)   2*eye(1)];
A2 = blkdiag(zeros(1),-eye(1),-eye(1));
B1 = [zeros(1);
      zeros(1);
      D_bar_inv*Ts];
  
A = [    A1       A2;
     eye(3) zeros(3)];
B = [        B1;
     zeros(3,1)];

A_tilde = Formulate_N_PowerMatVector(N-1, A);%54x6
B_tilde = Formulate_N_RecurMat(N-1, A,B);%54x9
R_tilde = Formulate_N_BlkdiagMat(N-1, R);%9x9

K_bar = Formulate_N_BlkdiagMat(2, [1 0 0;0 1 0]);%4x6

U_lev1 = K_bar'*Q_const*K_bar;
L_lev1 = Formulate_N_BlkdiagMat(N-1, U_lev1);%54x54
Q_tilde = L_lev1;

QB_tilde = Formulate_N_BlkdiagMat(N-1, Q_const*K_bar)*B_tilde;%36x54 * 54x9 = 36x9
AQB_tilde = A_tilde'*Q_tilde*B_tilde;%6x9


H = R_tilde+B_tilde'*L_lev1*B_tilde;%9x9


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
I_bar = kron(tril(ones(N-1)),eye(1));%9x9

tau_max = 1000;
tau_min = -tau_max;
dtau_max = 200;
dtau_min = -dtau_max;

tau_max_bar = tau_max*ones((N-1),1);
tau_min_bar = tau_min*ones((N-1),1);
dtau_max_bar = dtau_max*ones((N-1),1);
dtau_min_bar = dtau_min*ones((N-1),1);

% Matrix representation of inequality constraints
L1 = [eye(1) zeros(1,5)];
L2 = [zeros(1,1) eye(1) zeros(1,4)];

L1_bar = Formulate_N_BlkdiagMat(N-1, L1); %9x54
L2_bar = Formulate_N_BlkdiagMat(N-1, L2); %9x54

L1_tilde = L1_bar*A_tilde; %9x6
L2_tilde = L2_bar*A_tilde; %9x6
W1 = L1_bar*B_tilde;%9x9
W2 = L2_bar*B_tilde;%9x9


%% Parameters used for qpOASES
% H
H_QP = reshape(H,((N-1))^2,1);

% lb & ub
lb_QP = dtau_min_bar;
ub_QP = dtau_max_bar;

% with qd constraints
[m,n]=size([W1;W2;I_bar]);
A_QP = reshape([W1;W2;I_bar]',m*n,1);

lbA_QP_ini = [ repmat(q_min,N-1,1);
              repmat(qd_min,N-1,1);
                       tau_min_bar];
ubA_QP_ini = [ repmat(q_max,N-1,1);
              repmat(qd_max,N-1,1);
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
g = 9.81;
% L = exJoint.len/100/2;
L = 1;
m = 1;

a21 = -(m*g*L)/M_bar-K_b/M_bar;
a23 = K_b/M_bar;
a41 = K_b/D_bar;
a43 = -K_b/D_bar;
% A_mani = eye(4)+Ts*[0     1     0     0;
%                     a21   0     a23   0;
%                     0     0     0     1;
%                     a41   0     a43   0];
A_mani = [0     1     0     0;
          a21   0     a23   0;
          0     0     0     1;
          a41   0     a43   0];

%% Initialization for simulink
tau_sim_ini = 0;
q_sim_ini = q_ini;
q_bar_sim_ini = q_bar_ini;
theta_sim_ini = q_ini;
X_bar_sim_ini = [q_bar_sim_ini;theta_sim_ini];

T_run = Ts*(n_ini_stop+n_ref_times*n_ref_2pi-N-5);



%%% End of file


















