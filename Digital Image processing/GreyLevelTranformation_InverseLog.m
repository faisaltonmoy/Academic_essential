I = imread('D:\Education\4.2\Y_DIP\MATLAB prac\input_rose.jpg');
%   The Inverse log transformations can be defined by this formula
%   K = (10 ^ (log(I + 1) / c)) - 1

I = rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

I=im2double(I);
[row, col] = size(I);

c = 1.5;
K = zeros(row, col);
for i = 1:row
    for j = 1:col
        K(i,j) = (10 ^ (I(i,j) / c)) - 1;
    end
end
figure; 
imshow(K);
title 'Transformed Image'

figure;
plot(I,K,'.r');