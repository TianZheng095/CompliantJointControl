function X_r_lev1_test  = testMatlab(Ts,n_max_ref,q_ini,q_max_ref)
const_trans2degree = 180/pi;
t = 0:Ts:Ts*n_max_ref;
T = Ts*n_max_ref;
w = (2*pi)/T;
phi = -0.5*pi;
A = (q_max_ref-q_ini)/2;
b = q_ini;
X_r_lev1_test = A*sin(w*t+phi)+b+A;
figure;
plot(const_trans2degree*X_r_lev1_test(1:n_max_ref),'-r'); title('reference link joint');
end

