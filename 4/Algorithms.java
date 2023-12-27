import javafx.stage.Stage;

import java.util.ArrayList;

class Pair<A, B> {
    private A first;
    private B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }

    public A getFirst() {
        return first;
    }

    public B getSecond() {
        return second;
    }

    public void setFirst(A first) {
        this.first = first;
    }

    public void setSecond(B second) {
        this.second = second;
    }
}
public class Algorithms {
    double xStart, yStart, xEnd, yEnd;
    Algorithms(double x1, double y1, double x2, double y2){
        xStart = x1;
        yStart = y1;
        xEnd = x2;
        yEnd = y2;
    }
    public ArrayList<Pair<Double, Double>> stepsAlgorithm(){
        double x, y, steps;
        steps = (Math.abs(this.xEnd - this.xStart) > Math.abs(this.yEnd - this.yStart) ? Math.abs(this.xEnd - this.xStart) : Math.abs(this.yEnd - this.yStart));
        x = this.xStart;
        y = this.yStart;
        double x_inc = Math.abs(this.xEnd - this.xStart) / steps;
        double y_inc = Math.abs(this.yEnd - this.yStart) / steps;

        ArrayList<Pair<Double, Double>> points = new ArrayList<>();
        points.add(new Pair<>(x, y));
        while(steps > 0)
        {
            x += x_inc;
            y += y_inc;
            points.add(new Pair<>(x, y));
            --steps;
        }
        return points;
    }

    public ArrayList<Pair<Double, Double>> DDA(){
        double x, y, steps;
        steps = (Math.abs(this.xEnd - this.xStart) > Math.abs(this.yEnd - this.yStart) ? Math.abs(this.xEnd - this.xStart) : Math.abs(this.yEnd - this.yStart));
        x = this.xStart;
        y = this.yStart;
        double x_diff = Math.abs(this.xEnd - this.xStart);
        double y_diff = Math.abs(this.yEnd - this.yStart);

        ArrayList<Pair<Double, Double>> points = new ArrayList<>();
        points.add(new Pair<>(x, y));
        double x_inc, y_inc;
        if(x_diff > y_diff){
            x_inc = 1;
            y_inc = y_diff / x_diff;
        } else {
            x_inc = x_diff / y_diff;
            y_inc = 1;
        }
        int count = 1;
        while(count <= steps)
        {
            x = this.xStart + count * x_inc;
            y = this.yStart + count * y_inc;
            points.add(new Pair<>(x, y));
            ++count;
        }
        return points;
    }

    public ArrayList<Pair<Double, Double>> Bresenham(){
        double x, y;
        x = this.xStart;
        y = this.yStart;
        double dx = Math.abs(this.xEnd - this.xStart);
        double dy = Math.abs(this.yEnd - this.yStart);
        double d = dy / dx - 0.5;

        ArrayList<Pair<Double, Double>> points = new ArrayList<>();
        points.add(new Pair<>(x, y));
        while(x < this.xEnd)
        {
            if (d < 0){
                ++x;
                d += dy / dx;
            } else {
                ++x;
                ++y;
                d += dy / dx - 1;
            }
            points.add(new Pair<>(x, y));
        }
        return points;
    }

    public ArrayList<Pair<Double, Double>> BresenhamCircle(Stage stage){
        double xC = stage.getWidth() / 4, yC = stage.getHeight() / 4;

        double radius = 100;
        double x = 0, y = radius, d = 3 - 2 * radius;

        ArrayList<Pair<Double, Double>> points = new ArrayList<>();
        while(x <= y)
        {
            points.add(new Pair<>(xC + x, yC + y));
            points.add(new Pair<>(xC + x, yC - y));
            points.add(new Pair<>(xC - x, yC + y));
            points.add(new Pair<>(xC - x, yC - y));
            points.add(new Pair<>(xC + y, yC + x));
            points.add(new Pair<>(xC + y, yC - x));
            points.add(new Pair<>(xC - y, yC + x));
            points.add(new Pair<>(xC - y, yC - x));

            if (d < 0) {
                d += 4 * x + 6;
            } else {
                d += 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
        return points;
    }
}