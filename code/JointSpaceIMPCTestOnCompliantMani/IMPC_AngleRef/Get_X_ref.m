function Xr = Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref,mm)
    t = 0:Ts:Ts*n_ref_2pi*n_ref_times;
    omg = 2*pi/(Ts*n_ref_2pi);
    
%     amp_ref = [0.8;
%                0.2;
%                0.5];
%     amp_ref = pi/4;
    amp_ref = 0.5;
    joint_ref = amp_ref+amp_ref*sin(omg*t-pi/2);
    joint_d_ref = amp_ref*omg*cos(omg*t-pi/2);

    Xr = [joint_ref;
          joint_d_ref];

    Xr_ini_stop = kron(Xr(:,1),ones(1,n_ini_stop));
    Xr = [Xr_ini_stop Xr];

%% theta_dot reference
%     mm = M_bar*(1/(K_b*Ts*Ts));
    theta_r_k_total = [];
    for j = 2:30000
         
        
    
        theta_r_k = mm*(Xr(2,j+1)-(2-1/mm)*Xr(2,j)+Xr(2,j-1));
        theta_r_k_total = [theta_r_k_total;
                           theta_r_k];
              
    end
    theta_r_k_total=[0;0;theta_r_k_total];
    theta_r_k_total(5001:5002)=[0;0];
    
%     Xr(3:4,2:end) = Xr(3:4,1:end-1);
%     Xr(3:4,1) = Xr(3:4,2);
    
    
    Xr = [Xr;theta_r_k_total'];

    
    if plot_ref == 1       
        figure;
        t_plot = 0:Ts:Ts*(n_ref_2pi*n_ref_times+n_ini_stop);
        plot(t_plot,rad2deg(Xr(1,:)));     
        
        figure;
        plot(t_plot,rad2deg(Xr(2,:)));     

        hold on
        plot(t_plot,rad2deg(Xr(3,:))); 

    end

    
end

























