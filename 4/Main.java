import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.scene.control.*;

import java.util.ArrayList;

public class Main extends Application {
    private double GRID_SIZE;
    private int algCase;
    private int value = 10;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage){
        primaryStage.setWidth(800);
        primaryStage.setHeight(600);
        primaryStage.setTitle("Raster algorithms");
        Label inputX1 = new Label("X1:");
        Label inputX2 = new Label("X2:");
        Label inputY1 = new Label("Y1:");
        Label inputY2 = new Label("Y2:");

        TextArea x1Area = new TextArea();
        x1Area.setPrefColumnCount(5);
        x1Area.setPrefRowCount(1);
        TextArea x2Area = new TextArea();
        x2Area.setPrefColumnCount(5);
        x2Area.setPrefRowCount(1);
        TextArea y1Area = new TextArea();
        y1Area.setPrefColumnCount(5);
        y1Area.setPrefRowCount(1);
        TextArea y2Area = new TextArea();
        y2Area.setPrefColumnCount(5);
        y2Area.setPrefRowCount(1);

        VBox labels1 = new VBox(15, inputX1, inputX2);
        labels1.setAlignment(Pos.CENTER);
        VBox areas1 = new VBox(15, x1Area, x2Area);
        areas1.setAlignment(Pos.CENTER);
        VBox labels2 = new VBox(15, inputY1, inputY2);
        labels2.setAlignment(Pos.CENTER);
        VBox areas2 = new VBox(15, y1Area, y2Area);
        areas2.setAlignment(Pos.CENTER);
        HBox hbox1 = new HBox(10, labels1, areas1);
        HBox hbox2 = new HBox(10, labels2, areas2);
        HBox hboxAll = new HBox(10, hbox1, hbox2);
        hboxAll.setAlignment(Pos.CENTER);

        Canvas canvas = new Canvas(primaryStage.getWidth() / 2, primaryStage.getHeight() / 2);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        drawCoordinateSystem(gc, primaryStage, value);

        Button step = new Button("Step algorithm");
        step.setFont(Font.font(13));
        step.setMaxSize(230, 20);
        step.setOnAction(e -> {
            algCase = 1;
            if (x1Area.getText() == "" || y1Area.getText() == "" || x2Area.getText() == "" || y2Area.getText() == ""){
                Alert alert = new Alert(Alert.AlertType.WARNING);
                alert.setTitle("Warning");
                alert.setHeaderText("Input coordinates first!");
                alert.showAndWait();
            } else {
                gc.clearRect(0, 0, primaryStage.getWidth(), primaryStage.getHeight());
                drawCoordinateSystem(gc, primaryStage, value);
                draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
            }
        });

        Button ddaButton = new Button("DDA");
        ddaButton.setFont(Font.font(13));
        ddaButton.setMaxSize(230, 20);
        ddaButton.setOnAction(e -> {
            algCase = 2;
            if (x1Area.getText() == "" || y1Area.getText() == "" || x2Area.getText() == "" || y2Area.getText() == ""){
                Alert alert = new Alert(Alert.AlertType.WARNING);
                alert.setTitle("Warning");
                alert.setHeaderText("Input coordinates first!");
                alert.showAndWait();
            } else {
                gc.clearRect(0, 0, primaryStage.getWidth(), primaryStage.getHeight());
                drawCoordinateSystem(gc, primaryStage, value);
                draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
            }
        });

        Button bresenham = new Button("Bresenham algorithm");
        bresenham.setFont(Font.font(13));
        bresenham.setMaxSize(230, 20);
        bresenham.setOnAction(e -> {
            algCase = 3;
            if (x1Area.getText() == "" || y1Area.getText() == "" || x2Area.getText() == "" || y2Area.getText() == ""){
                Alert alert = new Alert(Alert.AlertType.WARNING);
                alert.setTitle("Warning");
                alert.setHeaderText("Input coordinates first!");
                alert.showAndWait();
            } else {
                gc.clearRect(0, 0, primaryStage.getWidth(), primaryStage.getHeight());
                drawCoordinateSystem(gc, primaryStage, value);
                draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
            }
        });

        Button bresenhamC = new Button("Bresenham algorithm (circle)");
        bresenhamC.setFont(Font.font(13));
        bresenhamC.setMaxSize(230, 20);
        bresenhamC.setOnAction(e -> {
            algCase = 4;
            if (x1Area.getText() == "" || y1Area.getText() == "" || x2Area.getText() == "" || y2Area.getText() == ""){
                Alert alert = new Alert(Alert.AlertType.WARNING);
                alert.setTitle("Warning");
                alert.setHeaderText("Input coordinates first!");
                alert.showAndWait();
            } else {
                gc.clearRect(0, 0, primaryStage.getWidth(), primaryStage.getHeight());
                drawCoordinateSystem(gc, primaryStage, value);
                draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
            }
        });

        SpinnerValueFactory<Integer> valueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(10, 50, 0, 1);
        Spinner<Integer> spinner = new Spinner<>(valueFactory);
        Label spinLabel = new Label("Set the grid:");

        VBox vboxAll = new VBox(10, hboxAll, step, ddaButton, bresenham, bresenhamC, spinLabel, spinner);
        vboxAll.setAlignment(Pos.CENTER_LEFT);
        HBox hbox = new HBox(20, vboxAll, canvas);
        hbox.setAlignment(Pos.CENTER);

        Scene scene = new Scene(hbox);
        primaryStage.setScene(scene);
        primaryStage.show();
        spinner.valueProperty().addListener((observable, oldValue, newValue) -> {
            value = spinner.getValue();
            redraw(gc, primaryStage, value);
            draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
        });
        scene.widthProperty().addListener((obs, oldVal, newVal) -> {
            canvas.setWidth(primaryStage.getWidth() / 2);
            redraw(gc, primaryStage, value);
            draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
        });
        scene.heightProperty().addListener((obs, oldVal, newVal) -> {
            canvas.setHeight(primaryStage.getHeight() / 2);
            redraw(gc, primaryStage, value);
            draw(primaryStage, canvas, gc, Double.parseDouble(x1Area.getText()), Double.parseDouble(y1Area.getText()), Double.parseDouble(x2Area.getText()), Double.parseDouble(y2Area.getText()), algCase);
        });
    }

    private void draw(Stage stage, Canvas canvas, GraphicsContext gc, double x1, double y1,
                      double x2, double y2, int algCase) {

        Algorithms algorithms = new Algorithms(Math.min(x1, x2),
                (x1 < x2) ? y1 : y2, Math.max(x1, x2), (x1 > x2) ? y1 : y2);

        ArrayList<Pair<Double, Double>> points = new ArrayList<>();

        switch(algCase){
            case 1:
                points = algorithms.stepsAlgorithm();
                drawPoints(points, gc, stage);
                break;
            case 2:
                points = algorithms.DDA();
                drawPoints(points, gc, stage);
                break;
            case 3:
                points = algorithms.Bresenham();
                drawPoints(points, gc, stage);
                break;
            case 4:
                points = algorithms.BresenhamCircle(stage);
                drawPointsCircle(points, gc, stage);
                break;
        }
    }

    private void drawPoints(ArrayList<Pair<Double, Double>> points, GraphicsContext gc, Stage stage) {
        final double pointSize = GRID_SIZE;
        gc.setFill(Color.RED);

        for (Pair<Double, Double> point : points) {
            double x = point.getFirst();
            double y = point.getSecond();
            gc.fillRect(stage.getWidth() / 4 + x * GRID_SIZE, stage.getHeight() / 4 - y * GRID_SIZE, pointSize, pointSize);
        }
    }
    private void drawPointsCircle(ArrayList<Pair<Double, Double>> points, GraphicsContext gc, Stage stage) {
        final double pointSize = GRID_SIZE / value * 1.5;
        gc.setFill(Color.RED);

        for (Pair<Double, Double> point : points) {
            double x = point.getFirst();
            double y = point.getSecond();
            gc.fillOval(x, y, pointSize, pointSize);
        }
    }
    private void redraw (GraphicsContext gc, Stage stage, int value) {
        gc.clearRect(0, 0, stage.getWidth(), stage.getHeight());
        drawCoordinateSystem(gc, stage, value);
    }
    private void drawCoordinateSystem(GraphicsContext gc, Stage stage, int value) {
        double width = stage.getWidth() / 2;
        double height = stage.getHeight() / 2;
        GRID_SIZE = width / (value * 2);
        double ratio = width / height;

        // Рисуем сетку
        gc.setStroke(Color.LIGHTGRAY);
        int counter = -(value - 1);
        int value1 = (int) (height / GRID_SIZE / 2);
        boolean check = true;
        String number = "";
        gc.setFill(Color.BLACK);
        for (double i = 0; i < width; i += GRID_SIZE) {
            gc.strokeLine(i, 0, i, height);
            if(counter <= 0 && i > 0){
                number = Integer.toString(counter);
                gc.fillText(number, i - 2, value1 * GRID_SIZE + 12);
                ++counter;
                if (counter == 0) ++counter;
            }
            else if (i > width / 2 && counter > 0 && counter < value) {
                number = Integer.toString(counter);
                gc.fillText(number, i - 2, value1 * GRID_SIZE + 12);
                ++counter;
            }
        }

        counter = value1 - 1;

        for (double i = 0; i < height; i += GRID_SIZE) {
            gc.strokeLine(0, i, width, i);
            if(counter >= 0 && i > 0){
                number = Integer.toString(counter);
                gc.fillText(number, width / 2 - 12, i - 2);
                --counter;
                if (counter == 0) --counter;
            }
            else if (i > height / 2 && counter < 0 && counter > -value) {
                number = Integer.toString(counter);
                gc.fillText(number, width / 2 - 14, i + 11);
                --counter;
            }
        }

        // Рисуем оси координат
        gc.setStroke(Color.BLACK);
        gc.setLineWidth(1);
        gc.strokeLine(0, value1 * GRID_SIZE, width, value1 * GRID_SIZE);
        gc.strokeLine(value * GRID_SIZE, 0, value * GRID_SIZE, height);
        
        // Подписываем координаты
        gc.setStroke(Color.BLACK);
        gc.fillText("0", value * GRID_SIZE + 2, value1 * GRID_SIZE + 12);
        gc.fillText("X", width - 10, value1 * GRID_SIZE - 2);
        gc.fillText("-X", 10, value1 * GRID_SIZE - 2);
        gc.fillText("Y", value * GRID_SIZE + 2, 10);
        gc.fillText("-Y", value * GRID_SIZE + 2, height - 2);
    }
}