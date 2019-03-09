# librarian
![build-status](https://travis-ci.org/davidkwan95/librarian.svg?branch=master)

Librarian is an app to search for books using Google API. It is created as a part of Chingu Voyage-8 prework. Librarian is built using `reason-react` as part of my learning.

Head to https://davidkwan95.github.io/librarian to give it a try

## Installation

### Prerequisite
* node (>= 10.15.3)
* yarn (>= 1.13.0)

```sh
yarn install
```

## Run Project

To start the server run `yarn start` and view in the browser at http://localhost:8000.

## Build for Production

```sh
yarn build
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).
