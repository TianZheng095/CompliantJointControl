result_path = 'D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef\parameter_testing_results'; %change under need
simulink_path = 'D:\master\master5\dlr\jointSpaceIMPC3DOF\IMPC_AngleRef_CompliantMani\IMPC_AngleRef'; %change under need
% threashold = 0.002; %change under need

for ii = 3:7
    %%parameter setting
    for jj = 0:4
        
        Q_const = 10^(ii);
        % R = 0.005;
        R = 0.0015+0.0001*jj;
    
        %%start simulink and plots saving
        sim("QP_lev2.slx");                                     %%%%run simulink
        Analyze;                                     %%%%plotting
        
        
        
        fp = strcat('Q=',num2str(Q_const),'R=',num2str(R));
                

        FilePath = strcat(result_path,fp);
        mkdir(FilePath);                                               %%%%create subfolder
        cd(FilePath);                                                  %%%%get into subfolder
        
        savefig(f_degree_joints_error,'error.fig');                      %%%%reference and real trajectory
        print(f_degree_joints_error,'-djpeg','error.jpg');
        
        savefig(f_degree_joints,'degree_joints.fig');                  %%%%7joint angles
        print(f_degree_joints,'-djpeg','degree_joints.jpg');
        
        savefig(f_tau,'tau.fig');%%%%7joint velocities
        print(f_tau,'-djpeg','tau.jpg');
        
        cd(simulink_path);

        
    end
end