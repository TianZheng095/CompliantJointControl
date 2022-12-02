function X_N_PowerMatVector = Formulate_N_PowerMatVector(N, X)
    
    X_N_PowerMatVector = [];
    for i = 0:N
       X_N_PowerMatVector = [X_N_PowerMatVector;
                             X^i]; 
              
    end
end