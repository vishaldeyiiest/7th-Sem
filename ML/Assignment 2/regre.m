function[avg_rmse] = regre(filename, order, valid)
warning('off', 'all');
M = readtable(filename);
%train = randperm(M, 4);
n = height(M);
X = M{1:n-1, 2};
T = M{1:n-1, 3};
K = 10;
if valid == 1
cv_K = cvpartition(n-1, 'kfold', K);
mse_k = ms_k = zeros(K, 1);
for k = 1:K
    tr_id = cv_K.training(k);
    te_id = cv_K.test(k);
    [ms_k(k), mse_k(k)] = gen(X(tr_id, :), T(tr_id, :), X(te_id, :), T(te_id, :), order, k);
end
disp(['testing: For k-fold cross validation: ', num2str(mean(mse_k))]);
disp(['Training: For k-fold cross validation: ', num2str(mean(ms_k))]);
end

%%%%
if valid == 2
cv_lout = cvpartition(n-1, 'leaveout');
mse_lout = zeros(K, 1);
for k = 1:K
    tr_id = cv_lout.training(k);
    te_id = cv_lout.test(k);
    mse_lout(k) = gen(X(tr_id, :), T(tr_id, :), X(te_id, :), T(te_id, :), order, k);
end
disp(['Testing: For leave-one out cross validation: ', num2str(mean(mse_lout))]);
end

%%%%
if valid == 3
mse_hold = zeros(K, 1);
for k = 1:K
    cv_hold = cvpartition(n-1, 'holdout', 7);
    tr_id = cv_hold.training(1);
    te_id = cv_hold.test(1);
    mse_hold(k) = gen(X(tr_id, :), T(tr_id, :), X(te_id, :), T(te_id, :), order, k);
end
disp(['Testing: For hold out cross validation: ', num2str(mean(mse_hold))]);
end