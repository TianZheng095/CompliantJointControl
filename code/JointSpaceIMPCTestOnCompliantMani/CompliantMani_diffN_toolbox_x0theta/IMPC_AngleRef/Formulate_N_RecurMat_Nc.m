function X_N_RecurMat = Formulate_N_RecurMat_Nc(Np,Nc, A,B)
%     N = N+1;
    
    X_N_RecurMat = [];
    H = [];
    
    m = size(A,1);
    n = size(B,2);
    
    for i = 1:Np
        for j = 1:Nc
            H = [H A^(i-j)*B];
            if j >= i
                break;
            end   
              
        end
        X_N_RecurMat = [X_N_RecurMat;H zeros(m,n*max(0,(Nc-i)))];
        H = [];
        
    end
    
    X_N_RecurMat = [zeros(m,Nc);X_N_RecurMat];
end


