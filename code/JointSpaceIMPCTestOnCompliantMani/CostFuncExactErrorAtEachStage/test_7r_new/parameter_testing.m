clc; close all; clear; 

result_path = 'D:\master\master3\DLR\onlycircle_test_7r_new\test_7r_new\parameter_testing_results'; %change under need
simulink_path = 'D:\master\master3\DLR\onlycircle_test_7r_new\test_7r_new'; %change under need
threashold = 0.002; %change under need

for ii = 6:6
    %%parameter setting
    for jj = 10:10
        for rr = 6:6
        k_p_lev1 = jj * 100; %%1000
        k_v_lev1 = jj * 10; %%100
        k_a_lev1 = 1;
        k_e_lev1 = [k_p_lev1;k_v_lev1;k_a_lev1];
    
        Q_const_lev1 = rr * 50; %%300
        R_const_lev1 = rr * 10; %%40
    
        M_factor = 0.05 * ii;
    
        %%start simulink and plots saving
        sim("kuka_IMPC_lev2.slx");                                     %%%%run simulink
        parameter_testing_Analyze;                                     %%%%plotting
        
        
        if flag==1
            fp = strcat('\rmse_error_lessthan',num2str(threashold),'M=',num2str(M_factor),'Kp=',num2str(k_p_lev1),'Kv=',num2str(k_v_lev1),'Q=',num2str(Q_const_lev1),'R=',num2str(R_const_lev1));
        else
            fp = strcat('\M=',num2str(M_factor),'Kp=',num2str(k_p_lev1),'Kv=',num2str(k_v_lev1),'Q=',num2str(Q_const_lev1),'R=',num2str(R_const_lev1));
        end         

        FilePath = strcat(result_path,fp);
        mkdir(FilePath);                                               %%%%create subfolder
        cd(FilePath);                                                  %%%%get into subfolder
        
        savefig(f_manipulator,'manipulator.fig');                      %%%%reference and real trajectory
        print(f_manipulator,'-djpeg','manipulator.jpg');
        
        savefig(f_degree_joints,'degree_joints.fig');                  %%%%7joint angles
        print(f_degree_joints,'-djpeg','degree_joints.jpg');
        
        savefig(f_degree_velocity_joints,'degree_velocity_joints.fig');%%%%7joint velocities
        print(f_degree_velocity_joints,'-djpeg','degree_velocity_joints.jpg');
        
        savefig(f_torque,'torque.fig');                                %%%%torque input
        print(f_torque,'-djpeg','torque.jpg');
        
        savefig(f_task_position_error,'task_position_error.fig');      %%%%TCP
        print(f_task_position_error,'-djpeg','task_position_error.jpg');
        
        savefig(f_task_velocity_error,'task_velocity_error.fig');      %%%%velocity
        print(f_task_velocity_error,'-djpeg','task_velocity_error.jpg');
        cd(simulink_path);

        end
    end
end


% open('***.fig','visible'); %%%%make figure visible
