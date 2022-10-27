function yr = Get_y_ref_step(Ts, n_ini_stop,n_ref_time)
    t = 0:Ts:Ts*(n_ref_time-1);
    
    joint_ref = [0 ones([1,size(t,2)-1])];
    

    yr = joint_ref;

    yr_ini_stop = kron(yr(:,1),ones(1,n_ini_stop));
    yr = [yr_ini_stop yr];
end

