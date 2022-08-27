I = (imread('D:\Education\4.2\Y_DIP\MATLAB prac\cameraman.png'));
%   The Power-law transformations can be defined by this formula
%   K = c * I^gamma

%I=rgb2gray(I);
figure;
imshow(I);
title 'Main Image'

I=im2double(I);
[row, col] = size(I);

c = 1;
g = 2.5;
K = zeros(row, col);
for i = 1:row
    for j = 1:col
        K(i,j) = c*(I(i,j).^g);
    end
end


J = imadjust(I,[],[],1);
figure; 

imshow(J);
title 'Transformed Image'

figure;
plot(I,J,'.r');