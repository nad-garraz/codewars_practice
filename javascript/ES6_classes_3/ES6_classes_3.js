/*
Fun with ES6 Classes #3 - Cuboids, Cubes and Getters
Task
Define the following classes.

I. Cuboid
The object constructor for the class Cuboid should receive exactly three arguments in the following order: length, width, height and store these three values in this.length, this.width and this.height respectively.

The class Cuboid should then have a getter surfaceArea which returns the surface area of the cuboid and a getter volume which returns the volume of the cuboid.

II. Cube
class Cube is a subclass of class Cuboid. The constructor function of Cube should receive one argument only, its length, and use that value passed in to set this.length, this.width and this.height.

Hint: Make a call to super, passing in the correct arguments, to make life easier ;)

Related Articles
Listed below are a few articles of interest that may help you complete this Kata:

Stack Overflow - What are getters and setters in ES6?
getter - Javascript | MDN
*/

class Cuboid {
  constructor(length, width, height) {
    Object.assign(this, {length, width, height})
  }
  
  get surFaceArea(){
    return 2 * (this.length * this.height + this.width * this.height + this.length * this.width);
  }

  get volume() {
    return  this.length * this.height * this.width;
  }
}

class Cube extends Cuboid {
  constructor(length){
   super(length, length, length);
  }
}

const Cubito = new Cuboid(1,2,3);
const Cubo = new Cube(1);

console.log(Cubito.surFaceArea);
console.log(Cubito.volume);
console.log(Cubo.surFaceArea);
console.log(Cubo.volume);
