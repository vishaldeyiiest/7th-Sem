M = readtable('2.csv');
n = height(M);
avg_x = M{n,2};
avg_t = M{n,3};
X = M{1:n-1, 2};
T = M{1:n-1, 3};
X2 = X.^2;
avg_xt = sum(X.*T)/(n-1);
w1 = (avg_xt - avg_t*avg_x)/(sum(X2)/(n-1)-avg_x^2);
w0 = avg_t - w1*avg_x;
pred = w0 + w1.*X;

%PLOT
figure;
subplot(1, 2, 1);
scatter(X, T);
hold on;
xlabel('X');
ylabel('T');
plot(X, X*w1+w0)
