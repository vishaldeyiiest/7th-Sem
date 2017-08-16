%function[T_pred] = reg(X, T, Xte, tr, te, order, index)
filename = '1.csv';
order = 45;
index = 1;
M = readtable(filename);
% %train = randperm(M, 4);
n = height(M);
X = M{1:n-1, 2};
Xb = X;
T = M{1:n-1, 3};
% avg_x = sum(X)/(n-1);
% avg_t = sum(T)/(n-1);
for i = 2:order
    temp = X.^i;
    Xb = [Xb temp];
    %Xt = Xb;
end

% avg_xt = sum(X.*T)/(n-1);
% w1 = (avg_xt - avg_t*avg_x)/(sum(X2)/(n-1)-avg_x^2);
% w0 = avg_t - w1*avg_x;
% pred = w0 + w1*X;
% disp(w0);
% disp(w1);
% p = w0+w1*x;
Xb = [ones(n-1, 1) Xb];
%disp(size(Xb));
W = inv(Xb.'*Xb)*Xb.'*T;
p = W.'*Xb.';
%PLOT
%subplot(1, 2, index);
%W = inv(X.'*X)*X'*T;
%disp(W);
hold on;
if index == 1
    plot(X, T, '.b');
else
    plot(X, T, '.m');
end
hold on;
xlabel('X');
ylabel('T');
plot(X, p, 'color', rand(1, 3))
%X_pred = [ones(te, 1), Xte];
% for i = 2:order
%     temp = Xte.^i;
%     X_pred = horzcat(X_pred, temp);
%     %Xt = Xb;
% end
disp(W)
%plot(Xte, W.'*X_pred.', 'ko');
%T_pred = W.'*X_pred.';
