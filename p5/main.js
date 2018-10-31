
var b;

function setup() {
    createCanvas(1280, 640);
    b = new Board(1280, 640, 20);

}

function draw() {

    b.draw()
}

function mousePressed() {
    b.addPoint();

}