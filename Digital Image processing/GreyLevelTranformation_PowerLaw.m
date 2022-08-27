I = (imread('Jerry.jpg'));
%   The Power-law transformations can be defined by this formula
%   K = c * I^gamma

I=rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

I=im2double(I);
[row, col] = size(I);

c = 5;
g = 1.5;
K = zeros(row, col);
for i = 1:row
    for j = 1:col
        K(i,j) = c*(I(i,j).^g);
    end
end
figure; 
imshow(K);
title 'Transformed Image'

figure;
plot(I,K,'.r');