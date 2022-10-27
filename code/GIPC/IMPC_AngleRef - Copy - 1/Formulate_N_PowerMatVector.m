function X_N_PowerMatVector = Formulate_N_PowerMatVector(start,ende, A,C)
    X_N_PowerMatVector = [];
    for i = 1:ende
       X_N_PowerMatVector = [X_N_PowerMatVector;
                             C*Formulate_N_sumA(start,i,A)]; 
              
    end
    
end