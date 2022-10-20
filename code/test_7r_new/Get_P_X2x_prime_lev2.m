function P_X2x_prime_lev2 = Get_P_X2x_prime_lev2(k_e_lev2)
    P_X2x_prime_lev2 = [k_e_lev2(1)*eye(3) k_e_lev2(2)*eye(3) eye(3)]*[eye(9) zeros(9)];
    
end
