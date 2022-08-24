I = imread('D:\Education\4.2\Y_DIP\MATLAB prac\BW-Rose.jpg');

I = rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

I=im2double(I);
[row, col] = size(I);

c = 1;
K = zeros(row, col);
for i = 1:row
    for j = 1:col
        K(i,j) = (10 ^ (I(i,j) / c)) - 1;
    end
end
output = I;
for i = 100:row-100
    for j = 1:col-100
        output(i,j) = K(i,j);
    end
end
figure; 
imshow(output);
title 'Transformed Image'

figure;
plot(I,K,'.-k');