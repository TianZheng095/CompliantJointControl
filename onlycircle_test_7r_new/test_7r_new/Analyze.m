%% Analyze results
clc; close all;

% Load test data
load('Data\q.mat'); load('Data\qd.mat'); load('Data\T.mat'); load('Data\X_ee.mat');load('Data\Xd_ee.mat'); load('Data\Eul_ee.mat'); 
q = q(2:end,:); qd = qd(2:end,:); T = T(2:end,:); x_ee = x_ee(2:end,:); xd_ee = xd_ee(2:end,:); eul_ee = eul_ee(2:end,:);

% Basic parameters
n_plot = max(size(x_ee));
% n_plot = 1500;
const_trans2degree = 180/pi;
n_stroboscopic = 20; linewidth = 0.6;

% Plot Stroboscopic motion of manipulator
show(kuka, q_ini); hold on;
plot3(X_r_lev1(1,:),X_r_lev1(2,:),X_r_lev1(3,:),'b','LineWidth',1); 
plot3(x_ee(1,1:n_plot),x_ee(2,1:n_plot),x_ee(3,1:n_plot),'r','LineWidth',1);


% Plot degree & degree velocity of joints 
figure;
subplot(7,1,1); plot(const_trans2degree*q(1,1:n_plot),'-r'); title('q of 1st joint');
subplot(7,1,2); plot(const_trans2degree*q(2,1:n_plot),'-r'); title('q of 2nd joint'); 
subplot(7,1,3); plot(const_trans2degree*q(3,1:n_plot),'-r'); title('q of 3rd joint'); 
subplot(7,1,4); plot(const_trans2degree*q(4,1:n_plot),'-r'); title('q of 4rd joint'); 
subplot(7,1,5); plot(const_trans2degree*q(5,1:n_plot),'-r'); title('q of 5rd joint'); 
subplot(7,1,6); plot(const_trans2degree*q(6,1:n_plot),'-r'); title('q of 6rd joint'); 
subplot(7,1,7); plot(const_trans2degree*q(7,1:n_plot),'-r'); title('q of 7rd joint'); 

figure;
subplot(7,1,1); plot(const_trans2degree*qd(1,1:n_plot),'-r'); title('qd of 1st joint');
subplot(7,1,2); plot(const_trans2degree*qd(2,1:n_plot),'-r'); title('qd of 2nd joint'); 
subplot(7,1,3); plot(const_trans2degree*qd(3,1:n_plot),'-r'); title('qd of 3rd joint'); 
subplot(7,1,4); plot(const_trans2degree*qd(4,1:n_plot),'-r'); title('qd of 4rd joint'); 
subplot(7,1,5); plot(const_trans2degree*qd(5,1:n_plot),'-r'); title('qd of 5rd joint'); 
subplot(7,1,6); plot(const_trans2degree*qd(6,1:n_plot),'-r'); title('qd of 6rd joint'); 
subplot(7,1,7); plot(const_trans2degree*qd(7,1:n_plot),'-r'); title('qd of 7rd joint'); 

% Plot control signals
figure;
subplot(7,1,1); plot(T(1,1:n_plot),'-b'); title('u of 1st joint');
subplot(7,1,2); plot(T(2,1:n_plot),'-b'); title('u of 2nd joint');
subplot(7,1,3); plot(T(3,1:n_plot),'-b'); title('u of 3rd joint');
subplot(7,1,4); plot(T(4,1:n_plot),'-b'); title('u of 4st joint');
subplot(7,1,5); plot(T(5,1:n_plot),'-b'); title('u of 5nd joint');
subplot(7,1,6); plot(T(6,1:n_plot),'-b'); title('u of 6rd joint');
subplot(7,1,7); plot(T(7,1:n_plot),'-b'); title('u of 7st joint');


%% Plot control performance of level 1
figure;
subplot(6,1,1); plot(1:n_plot,[x_ee(1,1:n_plot);X_r_lev1(1,1:n_plot)]); legend('X of EE','X Reference');
subplot(6,1,2); plot(1:n_plot,[x_ee(2,1:n_plot);X_r_lev1(2,1:n_plot)]); legend('Y of EE','Y Reference');
subplot(6,1,3); plot(1:n_plot,[x_ee(3,1:n_plot);X_r_lev1(3,1:n_plot)]); legend('Z of EE','Z Reference');
subplot(6,1,4); plot(1:n_plot,[x_ee(1,1:n_plot)-X_r_lev1(1,1:n_plot)]); legend('Error of X');
subplot(6,1,5); plot(1:n_plot,[x_ee(2,1:n_plot)-X_r_lev1(2,1:n_plot)]); legend('Error of Y');
subplot(6,1,6); plot(1:n_plot,[x_ee(3,1:n_plot)-X_r_lev1(3,1:n_plot)]); legend('Error of Z');

figure;
subplot(7,1,1); plot(1:n_plot,[xd_ee(1,1:n_plot);Xd_r_lev1(1,1:n_plot)]); legend('Xd of EE','Xd Reference');
subplot(7,1,2); plot(1:n_plot,[xd_ee(2,1:n_plot);Xd_r_lev1(2,1:n_plot)]); legend('Yd of EE','Yd Reference');
subplot(7,1,3); plot(1:n_plot,[xd_ee(3,1:n_plot);Xd_r_lev1(3,1:n_plot)]); legend('Zd of EE','Zd Reference');
subplot(7,1,4); plot(1:n_plot,[xd_ee(1,1:n_plot)-Xd_r_lev1(1,1:n_plot)]); legend('Error of Xd');
subplot(7,1,5); plot(1:n_plot,[xd_ee(2,1:n_plot)-Xd_r_lev1(2,1:n_plot)]); legend('Error of Yd');
subplot(7,1,6); plot(1:n_plot,[xd_ee(3,1:n_plot)-Xd_r_lev1(3,1:n_plot)]); legend('Error of Zd');

% Plot euler angle
figure;
subplot(8,1,1); plot(1:n_plot,const_trans2degree*[eul_ee(1,1:n_plot)]); legend('X Eular angle');
subplot(8,1,2); plot(1:n_plot,const_trans2degree*[eul_ee(2,1:n_plot)]); legend('Y Eular angle');
subplot(8,1,3); plot(1:n_plot,const_trans2degree*[eul_ee(3,1:n_plot)]); legend('Z Eular angle');

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




