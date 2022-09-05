
module.exports = {
    "env": {
        "browser": true,
        "es2021": true
    },
    "extends": [
        "airbnb-typescript/base", 
        "plugin:@typescript-eslint/recommended", 
        "plugin:@typescript-eslint/recommended-requiring-type-checking",
        "plugin:eslint-comments/recommended"
    ],
    "ignorePatterns": [
        "*eslint*",
        "__tests__/*",
        "docs/*",
        "node_modules/*",
        "dist/*",
        "jest.config.ts",
    ],
    "overrides": [
    ],
    "parserOptions": {
        "tsconfigRootDir": __dirname,
        "project": "./tsconfig.json",
        "ecmaVersion": "latest",
        "sourceType": "module"
    },
    "plugins": [
        "eslint-plugin-jsdoc",
        "import"
    ],
    "rules": {
        'jsdoc/require-jsdoc': ["error", {checkConstructors: false, contexts: ["ClassDeclaration", "FunctionDeclaration", "MethodDefinition", "ArrowFunctionExpression"] }],
        "jsdoc/check-alignment": "error",
        "jsdoc/check-indentation": "error",
        "jsdoc/newline-after-description": "error",
        "jsdoc/require-returns" : "error",
        "jsdoc/require-param": "error",
        "jsdoc/require-param-type": "error",
        "jsdoc/require-param-name": "error",
        "jsdoc/require-param-description": "error",
        "jsdoc/require-description": ["error", { descriptionStyle:"tag", contexts:['ClassDeclaration', 'ClassProperty', 'FunctionDeclaration', 'MethodDefinition', 'ArrowFunctionExpression']}],
        "max-classes-per-file": [
            "error",
            1
        ],
        "@typescript-eslint/explicit-function-return-type": "error",
        "@typescript-eslint/no-inferrable-types": "off",
        "@typescript-eslint/no-unused-vars": "error",
        "eslint-comments/no-use": ["warn"],
        "@typescript-eslint/no-namespace":"off"
    }
}