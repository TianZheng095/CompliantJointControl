function [B1_dtau] = Get_B1_dtau(Ts,M_bar_inv, J)   
    B1_dtau = [    zeros(3,7);
               Ts*J*M_bar_inv;
                  J*M_bar_inv;
                   zeros(9,7)];     
            
end