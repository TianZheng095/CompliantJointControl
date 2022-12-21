%% Analyze results
clc; close all;

% Load test data
load('Data\q.mat'); load('Data\qd.mat'); load('Data\qdd.mat'); load('Data\T.mat'); 
q = q(2:end,:); qd = qd(2:end,:); qdd = qdd(2:end,:); T = T(2:end,:); 

% Basic parameters
n_plot = max(size(q));
const_trans2degree = 180/pi;

% Plot degree & degree velocity of joints & 
% figure;
f_degree_joints_error = figure(1);
% set(f_degree_joints_error,'visible','off');
subplot(3,1,1); plot(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)),'-r'); title('e of q');
subplot(3,1,2); plot(const_trans2degree*(qd(1,1:n_plot)-Xr(2,1:n_plot)),'-r'); title('e of qd');
subplot(3,1,3); plot(const_trans2degree*(qdd(1,1:n_plot)-joint_dd_ref(1:n_plot)),'-r'); title('e of qdd');

% Plot degree & degree velocity of joints & 
% figure;
f_degree_joints = figure(2);
% set(f_degree_joints,'visible','off');
subplot(3,1,1); plot(const_trans2degree*q(1,1:n_plot),'-r'); title('q');
hold on 
plot(const_trans2degree*Xr(1,1:n_plot),'-b'); 
subplot(3,1,2); plot(const_trans2degree*qd(1,1:n_plot),'-r'); title('qd');
hold on 
plot(const_trans2degree*Xr(2,1:n_plot),'-b'); 
subplot(3,1,3); plot(const_trans2degree*qdd(1,1:n_plot),'-r'); title('qdd');
hold on 
plot(const_trans2degree*joint_dd_ref(1:n_plot),'-b'); 

% Plot control signals
% figure;
f_tau = figure(3);
% set(f_tau,'visible','off');
plot(T(1,1:n_plot),'-b'); title('motor torque');


load('UsingTime_IMPC_Np10_Nc3.mat'); 
time = figure(4);
% set(time,'visible','off');
time_n_plot = max(size(UsingTime_IMPC_Np10_Nc3));
plot(UsingTime_IMPC_Np10_Nc3(2,2:time_n_plot));title('computing time');

% 
% 
% % error = sqrt(mean(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)).^2));
% error_max = max(abs(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot))));
% 
% if error_max<threashold
%     flag = 1;
% else
%     flag = 0;
% end

%% error test
% FilePath = "D:\master\master5\dlr\jointSpaceIMPC3DOF\CompliantMani_diffN_toolbox_withx0theta\IMPC_AngleRef\errorData";
% cd(FilePath);
% savefig(time,'Nc5Np10_time.fig'); 
% savefig(f_degree_joints_error,'Nc5Np10_error.fig');
% Nc5Np10_time_mean = mean(UsingTime_IMPC_Np10_Nc3(2,2:time_n_plot));
% save('Nc5Np10_time.mat','Nc5Np10_time_mean');
% Nc5Np10_error_rmse = sqrt(mean((const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot))).^2));
% save('Nc5Np10_error.mat','Nc5Np10_error_rmse');
% FilePath = "D:\master\master5\dlr\jointSpaceIMPC3DOF\CompliantMani_diffN_toolbox_withx0theta\IMPC_AngleRef";
% cd(FilePath);
%% q constraint test
% FilePath = "D:\master\master5\dlr\jointSpaceIMPC3DOF\CompliantMani_diffN_toolbox_withx0theta\IMPC_AngleRef\qconstraintData";
% cd(FilePath);
% savefig(time,'Nc8Np15_time.fig'); 
% savefig(f_degree_joints_error,'Nc8Np15_error.fig');
% savefig(f_degree_joints,'Nc8Np15_compare.fig');
% 
% Nc8Np15_time_mean = mean(UsingTime_IMPC_Np10_Nc3(2,2:time_n_plot));
% save('Nc8Np15_time.mat','Nc8Np15_time_mean');
% error_ = (const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)));
% Nc8Np15_error_extend = const_trans2degree*max(q(1,1:n_plot))-40;
% error_count = [error_(1:6523),error_(8479:11523),error_(13479:15000)];
% Nc8Np15_error_rmse = sqrt(mean(error_count.^2));
% save('Nc8Np15_error.mat','Nc8Np15_error_extend','Nc8Np15_error_rmse');
% 
% FilePath = "D:\master\master5\dlr\jointSpaceIMPC3DOF\CompliantMani_diffN_toolbox_withx0theta\IMPC_AngleRef";
% cd(FilePath);
%% qd constraint test
% FilePath = "D:\master\master5\dlr\jointSpaceIMPC3DOF\CompliantMani_diffN_toolbox_withx0theta\IMPC_AngleRef\qdconstraintData";
% cd(FilePath);
% savefig(time,'Nc5Np5_time.fig'); 
% savefig(f_degree_joints_error,'Nc5Np5_error.fig');
% savefig(f_degree_joints,'Nc5Np5_compare.fig');
% 
% Nc5Np5_time_mean = mean(UsingTime_IMPC_Np10_Nc3(2,2:time_n_plot));
% save('Nc5Np5_time.mat','Nc5Np5_time_mean');
% error_ = (const_trans2degree*(qd(1,1:n_plot)-Xr(2,1:n_plot)));
% Nc5Np5_error_extend = max(const_trans2degree*max(qd(1,1:n_plot))-30,abs(const_trans2degree*min(qd(1,1:n_plot))+30));
% error_count = [error_(1:5744),error_(6758:8244),error_(9258:10744),error_(11758:13244),error_(14258:15000)];
% Nc5Np5_error_rmse = sqrt(mean(error_count.^2));
% save('Nc5Np5_error.mat','Nc5Np5_error_extend','Nc5Np5_error_rmse');
% 
% FilePath = "D:\master\master5\dlr\jointSpaceIMPC3DOF\CompliantMani_diffN_toolbox_withx0theta\IMPC_AngleRef";
% cd(FilePath);