function X_N_BlkdiagMat = Formulate_N_BlkdiagMat(N, X)
    X_N_BlkdiagMat = kron(eye(N),X);

%     X_bar = repmat({X},N,1);
%     X_N_blkdiag = blkdiag(X_bar{:});

end


