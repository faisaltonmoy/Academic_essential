input_img1=imread('input1.jpg');
input_img2=imread('input2.jpg');
A = 6;
B = 80;
C = A * B;
input_img1 = imresize(input_img1, [C C]);
input_img2 = imresize(input_img2, [C C]);
subplot(121);
imshow(input_img1);
title("Image 1");
subplot(122);
imshow(input_img2);
title("Image 2");
output = input_img1;
for i = 2 : 2 : A
    output(:, B * (i - 1) + 1 : B * i, :) = input_img2(:, B * (i - 1) + 1 : B * i, :);
end
figure;
%output = rgb2gray(output);
imshow(output);
imwrite(output, 'output.jpg');
title("Final Image");