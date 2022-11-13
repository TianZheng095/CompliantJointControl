function X_N_RecurMat = Formulate_N_RecurMat(N, A,B)
%     N = N+1;
    
    X_N_RecurMat = [];
    H = [];
    
    m = size(A,1);
    n = size(B,2);
    
    for i = 1:N
        for j = 1:N
            H = [H A^(i-j)*B];
            if j >= i
                break;
            end   
              
        end
        X_N_RecurMat = [X_N_RecurMat;H zeros(m,n*(N-i))];
        H = [];
        
    end
 
end


