function Xr = Get_q_ref(Ts,q_ini, n_ini_stop,n_max_ref, k_e_lev1,q_max_ref)
    %% Compute reference signal 
    t = 0:Ts:Ts*n_max_ref;    
%     const_trans2degree = 180/pi;
    omega = (q_max_ref-q_ini)/(Ts*n_max_ref);   
    
    % level 1 reference: link position from 0 to angle_max_lev1
    X_r_lev1 = q_ini+omega*t;
    Xd_r_lev1 = omega;
   
    
    Xprime_r_lev1 = k_e_lev1(1)*X_r_lev1+k_e_lev1(2)*Xd_r_lev1;
    
   
    
    % Add initial stop reference
    Xprime_r_ini_stop_lev1 = kron(k_e_lev1(1)*X_r_lev1(:,1),ones(1,n_ini_stop));
    Xprime_r_lev1 = [Xprime_r_ini_stop_lev1 Xprime_r_lev1];
    X_r_ini_stop_lev1 = kron(X_r_lev1(:,1),ones(1,n_ini_stop));
    X_r_lev1 = [X_r_ini_stop_lev1 X_r_lev1];
    
    
    Xr = {Xprime_r_lev1, X_r_lev1};
 
                
%     %% Plot
%     if plot_ref == 1     
%         % level 1
%         figure; 
%         show(kuka, q_ini); hold on;
%         plot3(X_r_lev1(1,:),X_r_lev1(2,:),X_r_lev1(3,:),'b','LineWidth',1); 
%         
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
% 
%         
%     end

    
end








