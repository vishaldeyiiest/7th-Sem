function[ms, mse] = gen(X, T, X_te, T_te, order, k)
%filename = '1.csv';
% M = readtable(filename);
n = numel(T);
% X = M{1:n-1, 2};
% order = 45;
% X = [ones(n-1, 1), X];

Y = [];
%T = M{1:n-1, 3};

for i = order:-1:1
    temp = order-i;
    for j = order:-1:1
        X_temp(i, j) = sum(X.^temp);
        temp = temp + 1;
    end
end
    
for i = order:-1:1
    Y(i) = sum((X.^(order-i)).*T);
end

W = X_temp\Y.';
pred = zeros(n, 1);
pred_te = zeros(numel(X_te), 1);
%Xb = [ones(n-1, 1), X_];
for i = 1:n
    for j = order:-1:1
        pred(i) = pred(i) + (X(i).^(order-j)).*W(j);
    end
end
for i = 1:numel(X_te)
    for j = order:-1:1
        pred_te(i) = pred_te(i) + (X_te(i).^(order-j)).*W(j);
    end
end
%disp(pred);
%subplot(5, 2, k);
plot(X, T, '.b');
hold on;
xlabel('X');
ylabel('T');
plot(X, pred, 'color', rand(1, 3))
ms = mean((pred - T).^2));
mse = mean((pred_te - T_te).^2);
rmse = sqrt(mse);
%disp(mse);