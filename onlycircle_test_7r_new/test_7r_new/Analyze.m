%% Analyze results
clc; close all;

% Load test data
load('Data\q.mat'); load('Data\qd.mat'); load('Data\T.mat'); 
% load('Data\X_ee.mat');load('Data\Xd_ee.mat'); load('Data\Eul_ee.mat'); 
q = q(2,:); qd = qd(2,:); T = T(2,:); 
% x_ee = x_ee(2:end,:); xd_ee = xd_ee(2:end,:); eul_ee = eul_ee(2:end,:);

% Basic parameters
n_plot = max(size(q));
% n_plot = 1500;
const_trans2degree = 180/pi;
% n_stroboscopic = 20; linewidth = 0.6;

% % Plot Stroboscopic motion of manipulator
% show(kuka, q_ini); hold on;
% plot3(X_r_lev1(1,:),X_r_lev1(2,:),X_r_lev1(3,:),'b','LineWidth',1); 
% plot3(x_ee(1,1:n_plot),x_ee(2,1:n_plot),x_ee(3,1:n_plot),'r','LineWidth',1);


% Plot degree & degree velocity of joints 
figure;
plot(const_trans2degree*q(1:n_plot),'-r'); title('link joint position');


figure;
plot(const_trans2degree*qd(1:n_plot),'-r'); title('link joint velocity');


% Plot control signals
figure;
plot(T(1:n_plot),'-b'); title('torque of link joint');



%% Plot control performance of level 1
figure;
subplot(2,1,1);plot(1:n_plot,[const_trans2degree*q(1:n_plot);const_trans2degree*X_r_lev1(1:n_plot)]); legend('link joint position','link joint position Reference');
subplot(2,1,2); plot(1:n_plot,[const_trans2degree*q(1:n_plot)-const_trans2degree*X_r_lev1(1:n_plot)]); legend('Error of link joint position');

figure;
subplot(2,1,1); plot(1:n_plot,[const_trans2degree*qd(1:n_plot);const_trans2degree*Xd_r_lev1(1:n_plot)]); legend('link joint velocity','link joint velocity Reference');
subplot(2,1,2); plot(1:n_plot,[const_trans2degree*qd(1:n_plot)-const_trans2degree*Xd_r_lev1(1:n_plot)]); legend('Error of link joint velocity');

% % Plot euler angle
% figure;
% subplot(8,1,1); plot(1:n_plot,const_trans2degree*[eul_ee(1,1:n_plot)]); legend('X Eular angle');
% subplot(8,1,2); plot(1:n_plot,const_trans2degree*[eul_ee(2,1:n_plot)]); legend('Y Eular angle');
% subplot(8,1,3); plot(1:n_plot,const_trans2degree*[eul_ee(3,1:n_plot)]); legend('Z Eular angle');

% % Plot Stroboscopic motion of manipulator
% figure
% show(kuka, q_ini); hold on;
% plot3(X_r_lev1(1,:),X_r_lev1(2,:),X_r_lev1(3,:),'b','LineWidth',1); 
% plot3(x_ee(1,1:n_plot),x_ee(2,1:n_plot),x_ee(3,1:n_plot),'r','LineWidth',1);
% set(gcf,'Visible','on');
% rc = rateControl(1/Ts);
% for i = 1:n_plot
%     show(kuka,q(:,i),FastUpdate=true,PreservePlot=false);
%     waitfor(rc);
% end




