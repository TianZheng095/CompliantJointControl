function X_N_RecurMat = Formulate_N_RecurMat(N, A,B,C)
%     N = N+1;
    
    X_N_RecurMat = [];
    H = [];
    
    m = size(C,1);
    n = size(B,2);
    
    for i = 1:N
        for j = 1:N
            H = [H C*Formulate_N_sumA(0,i-j,A)*B];
            if j >= i
                break;
            end   
              
        end
        X_N_RecurMat = [X_N_RecurMat;H zeros(m,n*(N-i))];
        H = [];
        
    end
 
end


