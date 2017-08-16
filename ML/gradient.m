function [ parameters, costv ] = gradient( x, y, parameters, learningRate, r )

    m = length(y);
    costv = zeros(r, 1); 
   
    for i = 1:r        
        h = (x * parameters - y)';        
    % Updating the parameters
    parameters(1) = parameters(1) - learningRate * (1/m) * h * x(:, 1);
    parameters(2) = parameters(2) - learningRate * (1/m) * h * x(:, 2);        
    costv(i) = cost(x, y, parameters);       
    end
end