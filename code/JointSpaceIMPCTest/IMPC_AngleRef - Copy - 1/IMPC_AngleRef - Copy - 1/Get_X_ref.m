function Xr = Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref)
    t = 0:Ts:Ts*n_ref_2pi*n_ref_times;
    omg = 2*pi/(Ts*n_ref_2pi);
    
%     amp_ref = [0.8;
%                0.2;
%                0.5];
    amp_ref = [0.5;
               0.5;
               0.5];
    joint_ref = [amp_ref(1)+amp_ref(1)*sin(omg*t-pi/2);
                 amp_ref(2)+amp_ref(2)*sin(omg*t-pi/2);
                 amp_ref(3)+amp_ref(3)*sin(omg*t-pi/2)];  
    joint_d_ref = [amp_ref(1)*omg*cos(omg*t-pi/2);
                   amp_ref(2)*omg*cos(omg*t-pi/2);
                   amp_ref(3)*omg*cos(omg*t-pi/2)]; 

    Xr = [joint_ref;
          joint_d_ref;
          joint_ref;
          joint_d_ref];

    Xr_ini_stop = kron(Xr(:,1),ones(1,n_ini_stop));
    Xr = [Xr_ini_stop Xr];
    
    Xr(6:12,2:end) = Xr(6:12,1:end-1);
    Xr(6:12,1) = Xr(6:12,2);
    
    
    if plot_ref == 1       
        figure;
        t_plot = 0:Ts:Ts*(n_ref_2pi*n_ref_times+n_ini_stop);
        plot(t_plot,rad2deg(Xr(1,:)),...
             t_plot,rad2deg(Xr(2,:)),...
             t_plot,rad2deg(Xr(3,:)));     
        
        figure;
        plot(t_plot,rad2deg(Xr(4,:)),...
             t_plot,rad2deg(Xr(5,:)),...
             t_plot,rad2deg(Xr(6,:)));     

    end

    
end

























