clc; close all; clear; 
result_path = 'D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef\parameter_test_results_nonlinear_thetad_r\results_'; %change under need
simulink_path = 'D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef'; %change under need
threashold = 5; %change under need


for ii = 1:10
    %%parameter setting
    for jj = 1:10
        for kk = 1:10
            for rr = 1:20
                
%                 Q_const_pos_error= 1000000*ii;
%                 Q_const_vel_error= 200*jj;
%                 Q_const_theta_error = 100*kk;
%                 R_const = 50*rr;
                
    
            
                %%start simulink and plots saving
                sim("QP_lev2.slx");                                     %%%%run simulink
                Analyze;                                     %%%%plotting
                
                if flag==1
    %                 fp = strcat('\rmse_error_lessthan',num2str(threashold),'M=',num2str(M_factor),'Kp=',num2str(k_p_lev1),'Kv=',num2str(k_v_lev1),'Q=',num2str(Q_const_lev1),'R=',num2str(R_const_lev1));
                    fp = strcat('\max_e_lessthan',num2str(threashold),'Q_pos=',num2str(Q_const_pos_error),'Q_vel=',num2str(Q_const_vel_error),'Q_thetad=',num2str(Q_const_theta_error),'R=',num2str(R_const));
    %             else
    %                 fp = strcat('Q=',num2str(Q_const),'R=',num2str(R_const),'Kp=',num2str(Kp));
    %             end  
                
    %             fp = strcat('Q=',num2str(Q_const),'R=',num2str(R_const),'Kp=',num2str(Kp));
                        
        
                    FilePath = strcat(result_path,fp);
                    mkdir(FilePath);                                               %%%%create subfolder
                    cd(FilePath);                                                  %%%%get into subfolder
                    
                    
                    % Load test data
                    load('D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef\Data\q.mat'); 
                    load('D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef\Data\qd.mat'); 
                    load('D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef\Data\T.mat'); 
                    q = q(2:end,:); qd = qd(2:end,:); T = T(2:end,:); 
                    
                    % Basic parameters
                    n_plot = max(size(q));
                    const_trans2degree = 180/pi;
                    
                    % Plot degree & degree velocity of joints & 
                    % figure;
                    f_degree_joints_error = figure(1);
                    set(f_degree_joints_error,'visible','off');
                    subplot(2,1,1); plot(const_trans2degree*(q(1,1:n_plot)-Xr(1,1:n_plot)),'-r'); title('e of q');
                    subplot(2,1,2); plot(const_trans2degree*(qd(1,1:n_plot)-Xr(2,1:n_plot)),'-r'); title('e of qd');
                    
                    
                    % Plot degree & degree velocity of joints & 
                    % figure;
                    f_degree_joints = figure(2);
                    set(f_degree_joints,'visible','off');
                    subplot(2,1,1); plot(const_trans2degree*q(1,1:n_plot),'-r'); title('q');
                    hold on 
                    plot(const_trans2degree*Xr(1,1:n_plot),'-b'); 
                    subplot(2,1,2); plot(const_trans2degree*qd(1,1:n_plot),'-r'); title('qd');
                    hold on 
                    plot(const_trans2degree*Xr(2,1:n_plot),'-b'); 
                    
                    % Plot control signals
                    % figure;
                    f_tau = figure(3);
                    set(f_tau,'visible','off');
                    plot(T(1,1:n_plot),'-b'); title('motor torque');
    
    
    
                    savefig(f_degree_joints_error,'error.fig');                      %%%%reference and real trajectory
                    print(f_degree_joints_error,'-djpeg','error.jpg');
                    
                    savefig(f_degree_joints,'degree_joints.fig');                  %%%%7joint angles
                    print(f_degree_joints,'-djpeg','degree_joints.jpg');
                    
                    savefig(f_tau,'tau.fig');%%%%7joint velocities
                    print(f_tau,'-djpeg','tau.jpg');
                    
                    cd(simulink_path);
                end
            end
        end
        
    end
end