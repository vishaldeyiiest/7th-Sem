function[avg_rmse] = main(filename, index, order)
M = readtable(filename);
%train = randperm(M, 4);
n = height(M);
X = M{1:n-1, 2};
T = M{1:n-1, 3};
%Xte = [1994, 1999, 2001];
% fcn = @(Xtr, Ytr, Xte) predict(...
%     GeneralizedLinearModel.fit(X, T,'linear','distr','poisson'), ...
%     Xte);
K = 3;
cv = cvpartition(numel(T), 'kfold', K);

mse = zeros(K,1);
for k=1:K
    % training/testing indices for this fold
    trainIdx = cv.training(k);
    testIdx = cv.test(k);
    
    %mdl = GeneralizedLinearModel.fit(X(trainIdx,:), Y(trainIdx), 'linear', 'Distribution','poisson');
    % predict regression output
    %Y_hat = predict(mdl, X(testIdx,:));
    T_pred = gen(X(trainIdx,:), T(trainIdx), X(testIdx,:), cv.TrainSize(k), cv.TestSize(k), order, index);
    % compute mean squared error
    mse(k) = mean((T(testIdx).' - T_pred).^2);
end

% average RMSE across k-folds
avrg_rmse = mean(sqrt(mse));
