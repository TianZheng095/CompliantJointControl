function [Xr,joint_dd_ref,pp] = Get_X_ref(Ts, n_ini_stop,n_ref_2pi,n_ref_times, plot_ref,mm)
tend =   Ts*n_ref_2pi*n_ref_times;  
t = 0:Ts:tend;
omg = 2*pi/(Ts*n_ref_2pi);
    
%% sinus trajectory
%     amp_ref = 0.5;
%     joint_ref = amp_ref+amp_ref*sin(omg*t-pi/2);
%     joint_d_ref = amp_ref*omg*cos(omg*t-pi/2);

%% 5th order polynomial trajectory
amp_ref = 0.5;
wpts = [kron(ones(1,n_ref_times),[0 amp_ref*2]),0];
tpts = 0:0.5*Ts*n_ref_2pi:tend;
tvec = 0:Ts:tend;
[joint_ref, joint_d_ref, joint_dd_ref, pp] = quinticpolytraj(wpts, tpts, tvec);
% plot(tvec, joint_dd_ref)
% hold all
% plot(tpts, wpts, 'x')
% xlabel('t')
% ylabel('Positions')
% % legend('X-positions','Y-positions')
% hold off



%% smooth step trajectory
%     Tr = 1;
%     a = pi/180;
%     t50 = 2;
%     x1 = @(t)a./(1+exp(-4*(t-t50)/Tr));
%     joint_ref = x1(t);
%     x2 = @(t)(4*a*exp(-4*(t-t50)/Tr))./((1+exp(-4*(t-t50)/Tr)).^2);
%     joint_d_ref = x2(t);

    Xr = [joint_ref;
          joint_d_ref];

    Xr_ini_stop = kron(Xr(:,1),ones(1,n_ini_stop));
    Xr = [Xr_ini_stop Xr];


    Xddr_ini_stop = kron(joint_dd_ref(:,1),ones(1,n_ini_stop));
    joint_dd_ref = [Xddr_ini_stop joint_dd_ref];

%% theta_dot reference
% %     mm = M_bar*(1/(K_b*Ts*Ts));
%     theta_r_k_total = [];
%     for j = 2:30000
%          
%         
%     
%         theta_r_k = mm*(Xr(2,j+1)-(2-1/mm)*Xr(2,j)+Xr(2,j-1));
%         theta_r_k_total = [theta_r_k_total;
%                            theta_r_k];
%               
%     end
%     theta_r_k_total=[0;0;theta_r_k_total];
%     theta_r_k_total(5001:5002)=[0;0];
%     
% %     Xr(3:4,2:end) = Xr(3:4,1:end-1);
% %     Xr(3:4,1) = Xr(3:4,2);
%     
%     
%     Xr = [Xr;theta_r_k_total'];

    
    if plot_ref == 1       
        figure;
        t_plot = 0:Ts:Ts*(n_ref_2pi*n_ref_times+n_ini_stop);
        plot(t_plot,rad2deg(Xr(1,:)));     
        
        figure;
        plot(t_plot,rad2deg(Xr(2,:)));     

%         hold on
%         plot(t_plot,rad2deg(Xr(3,:))); 

        
        figure;
        plot(t_plot,rad2deg(joint_dd_ref(:)));

    end

    
end

























