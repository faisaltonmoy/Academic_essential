I = (imread('Jerry.jpg'));
%   The log transformations can be defined by this formula
%   K = c log(I + 1)

I=rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

I=im2double(I);
[row, col] = size(I);

c = 3
K = zeros(row, col);
for i = 1:row
    for j = 1:col
        K(i,j) = c * log(I(i,j) + 1);
    end
end
figure; 
imshow(K);
title 'Transformed Image'

figure;
plot(I,K,'.r');