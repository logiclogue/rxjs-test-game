const HtmlWebpackPlugin = require("html-webpack-plugin");

const htmlPlugin = new HtmlWebpackPlugin({
    template: "./index.html",
    filename: "./index.html"
});

module.exports = {
    devtool: "source-maps",
    entry: {
        main: "./src/index.bs.js"
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: "babel-loader"
            }
        ]
    },
    plugins: [htmlPlugin]
};
