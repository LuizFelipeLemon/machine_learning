
var b,c;

function setup() {
    createCanvas(1280, 640);
    b = new Board(1280, 640, 20);
    c = new Car(5,5,34);

}

function draw() {

   // b.draw()
    c.show()
}

function mousePressed() {
    b.addPoint();

}