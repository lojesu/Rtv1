# Rtv1
![#https://github.com/lojesu/Rtv1/blob/master/screenshot/sphere1](https://github.com/lojesu/Rtv1/blob/master/screenshot/sphere1)
# Introduction
Rtv1 is a school project who asks notions of mathemathics in space. the goal is to create a scene in three dimension with basics mathematical forms(spheres, planes, cones and cylinder) and a light set.
# Get started
## Launch
Use:
```git clone https://github.com/lojesu/Rtv1.git; cd Rtv1; make```
## Launched a scene
Use:
```./rtv1 <scene path>```
# How create a scene ?

|object|infomation we need|how write in the scene file|
|:-:|:-:|:-:|
|spheres|we need a center, a point in space in 3d, a radius and a color|sphere(```x,y,z```/```dist```/```color```)|
|planes|we need a point in space, a norm who is a vector perpendicular to the plane and a color|plan(```x,y,z```/```x,y,z```/```color```)|
|cones|we need a point in space, a vector whichs represent the orientation of the cone, an angle that is the opening angle and a color|cone(```x,y,z```/```x,y,z```/```angle```/```color```)|
|cylinders|we need a point in space, a vector whichs represent the orientation of the cylinder, a radius and a color|cylinder(```x,y,z```/```x,y,z```/```dist```/```color```)|
|lights|we need a point in space and a pourcentage intensity|light(```x,y,z```/```intensity```)|
|camera|we need a point in space and a vector whichs represent the direction in which we look|cam(```x,y,z```/```x,y,z```)|

### more information about the light
we have three additional information about the light, ```specular light```, ```diffuse light``` and ```ambiant light```.
this is a pourcentage numbers for include this information and you must be have at least one light

|light|information|how write in the scene file|
|:-:|:-:|:-:|
|specular|direct reflexion light on objects|specular=x|
|diffuse|reflexion issued harmoniously on 360 around the light|diffuse=x|
|ambiant|this is the light that spreads even if there is no light|ambiant=x|

### information to know for create a scene
- the color must be an hexadecimal number(ex:0xff0000)
- the camera is basic on ```0,0,0``` and she look on ```0,0,1```
- we do not accept space between geomatrical informations
- individual maximum numbers of geomatricals forms is ```32```
- if you don't put a light and ambiant light is equal to zero you don't see the scene

## screenshot
![https://github.com/lojesu/Rtv1/blob/master/screenshot/scene1](https://github.com/lojesu/Rtv1/blob/master/screenshot/scene1)
![#https://github.com/lojesu/Rtv1/blob/master/screenshot/sphere2](https://github.com/lojesu/Rtv1/blob/master/screenshot/sphere2)

## Contributors
- lojesu
- reda-con
