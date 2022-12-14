function [Xr_all_level,Xd_r_lev1] = Get_X_ref(kuka,Ts,q_ini,Transform_ee_ini, n_ini_stop,n_max_ref, k_e_lev1,r_ref_1,angle_max_ref_1, plot_ref)
    %% Compute reference signal 
    t = 0:Ts:Ts*n_max_ref;
%     t = zeros(1,n_max_ref);
    const_trans2degree = 180/pi;
    omega = angle_max_ref_1/(Ts*n_max_ref);   

    % level 1 reference: TCP position
    Rot_ee_ini = Transform_ee_ini(1:3,1:3);
    trans_ee_ini = Transform_ee_ini(1:3,4);


    X_r_end = [-(r_ref_1-r_ref_1*cos(omega*t));
                         -r_ref_1*sin(omega*t);
                         -r_ref_1*sin(omega*t)];
    Xd_r_end = [-(r_ref_1*omega*sin(omega*t));
                  -r_ref_1*omega*cos(omega*t);
                  -r_ref_1*omega*cos(omega*t)];
    Xdd_r_end = [-(r_ref_1*omega^2*cos(omega*t));
                    r_ref_1*omega^2*sin(omega*t);
                    r_ref_1*omega^2*sin(omega*t)];
         
                         
                
    X_r_lev1 = Rot_ee_ini*X_r_end+trans_ee_ini;
    Xd_r_lev1 = Rot_ee_ini*Xd_r_end;
    Xdd_r_lev1 = Rot_ee_ini*Xdd_r_end;
    
    
    Xprime_r_lev1 = k_e_lev1(1)*X_r_lev1+k_e_lev1(2)*Xd_r_lev1+k_e_lev1(3)*Xdd_r_lev1;

    
    
    
    % Add initial stop reference
    Xprime_r_ini_stop_lev1 = kron(k_e_lev1(1)*X_r_lev1(:,1),ones(1,n_ini_stop));
    Xprime_r_lev1 = [Xprime_r_ini_stop_lev1 Xprime_r_lev1];
    X_r_ini_stop_lev1 = kron(X_r_lev1(:,1),ones(1,n_ini_stop));
    X_r_lev1 = [X_r_ini_stop_lev1 X_r_lev1];
    
    
    
    
    Xr_all_level = {Xprime_r_lev1, X_r_lev1};
    
 
                
    %% Plot
    if plot_ref == 1     
        % level 1
        figure; 
        show(kuka, q_ini); hold on;
        plot3(X_r_lev1(1,:),X_r_lev1(2,:),X_r_lev1(3,:),'b','LineWidth',1); 
        
%         % level 2        
%         figure;
%         subplot(3,1,1); plot(const_trans2degree*X_r_lev2(1,:));
%         subplot(3,1,2); plot(const_trans2degree*X_r_lev2(2,:));
%         subplot(3,1,3); plot(const_trans2degree*X_r_lev2(3,:));  
% 
%         % level 3        
%         figure;
%         plot(const_trans2degree*X_r_lev3,'b');     
%         title('Reference trajectory of joint 1');     

        
    end

    
end








