// Emre YALVAÇ
const addon = require('./build/Release/hex-generator').Guid;
module.exports = (length = 16) => {
    return addon(length);
}