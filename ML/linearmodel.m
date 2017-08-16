X = [0.1, 0.2, 0.26, 0.33, 0.42, 0.5, 0.58, 0.76, 0.82, 0.97, 1.2, 1.4, 1.55, 1.8];
Y = [0.08, 0.22, 0.3, 0.35, 0.54, 0.65, 0.73, 0.85, 0.92, 1.12, 1.4, 1.7, 1.8, 2]; 
 
scatter(X, Y)
hold on;
w0 = -0.05;
w1 = [1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6];
%plot(X, 1.2*X+0.15)

for var = drange(w1)
    plot(X, var*X+w0)
end

xlabel('X')
ylabel('Y')
best_w1 = 1.2;
mse = zeros(1, length(w1));
for v = drange(1:length(w1))
    for var = drange(1:10)
        mse(v) = mse(v) + (Y(var)-w1(v)*X(var)-w0)^2;
    end
end
rmse = sqrt(mse)

y_pred = zeros(1, 4);
error = 0;
for v = drange(11, 14)
    y_pred(v-10) = best_w1*X(v)+w0;
    error = error + (Y(v)-y_pred(v-10))^2
end

% Method of least squares
