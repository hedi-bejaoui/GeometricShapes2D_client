//
// Created by bejaoui on 12/28/2024.
//

class ShapeFactory {
public:
    static std::shared_ptr<Forme> load(std::istream& in) {
        std::string type;
        in >> type;

        if (type == "CIRCLE") {
            double x, y, radius;
            std::string color;
            in >> x >> y >> radius >> color;
            return std::make_shared<Cercle>(Vecteur2D(x, y), radius, color);
        } else if (type == "SEGMENT") {
            double x1, y1, x2, y2;
            std::string color;
            in >> x1 >> y1 >> x2 >> y2 >> color;
            return std::make_shared<Segment>(Vecteur2D(x1, y1), Vecteur2D(x2, y2), color);
        } else if (type == "TRIANGLE") {
            double x1, y1, x2, y2, x3, y3;
            std::string color;
            in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> color;
            return std::make_shared<Triangle>(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3), color);
        } else if (type == "POLYGONE") {
            int numPoints;
            in >> numPoints;
            std::vector<Vecteur2D> points(numPoints);
            for (int i = 0; i < numPoints; ++i) {
                double x, y;
                in >> x >> y;
                points[i] = Vecteur2D(x, y);
            }
            std::string color;
            in >> color;
            return std::make_shared<Polygone>(points, color);
        } else if (type == "GROUP") {
            std::string color;
            in >> color;
            auto group = std::make_shared<Groupe>(color);
            in.ignore(); // Ignore the '['
            while (in.peek() != ']') {
                group->addForme(load(in));
            }
            in.ignore(); // Ignore the ']'
            return group;
        }

        throw std::runtime_error("Unknown shape type: " + type);
    }
};
