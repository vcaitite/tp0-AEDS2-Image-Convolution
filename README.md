# Practical Work 0 of AEDS 2 - UFMG 

<h1 align="center">
     Image Convolution</a>
</h1>
<p align="justify"> This work aims to implement and apply the convolution operation in digital images to find its derivatives in the PGM format. This format stores a grayscale image. </p>

<p align="justify"> The Convolution Matrix filter uses a primary matrix, which is the image to be treated. This figure is treated as a matrix of pixels, which in the case of this work, all of these are numbers that are within the range [0, 255]. The core to be used will depend on the desired effect. In this process, a 3x3 size kernel is used.
The filter analyzes each pixel of the image successively. For each of them, which you can call them "initial pixel", the value of this pixel will be the sum of the multiplication of it and the 8 pixels around it by the corresponding value in the core matrix. These nine values are added and become the final value for that pixel. </p>

<p align="justify"> To run the program, just compile with gcc and then from the command line open the program and pass as arguments the file name of the original image and the name of the file to be created containing the converted image. Example: </p>

```
./program_name image_name.pgm converted_image_name.pgm
```
