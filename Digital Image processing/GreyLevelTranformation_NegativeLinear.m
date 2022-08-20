I = (imread('Jerry.jpg'));
%   The Negative Linear transformations can be defined by this formula
%   K = 255 - I

I=rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

[row, col] = size(I);

K = uint8(zeros(row, col));
for i = 1:row
    for j = 1:col
        K(i,j) = 255-I(i,j); 
    end
end

figure; 
imshow(K);
title 'Transformed Image'

figure;
plot(I,K,'.r');