I = (imread('Jerry.jpg'));
%   The Positive Linear transformations can be defined by this formula
%   K = I

I=rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

I=im2double(I);
[row, col] = size(I);

K = zeros(row, col);
for i = 1:row
    for j = 1:col
        K(i,j) = I(i,j);
    end
end
figure; 
imshow(K);
title 'Transformed Image'

figure;
plot(I,K,'.r');