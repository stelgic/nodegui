import { QLabel } from '../QLabel';
import { QPixmap } from '../../QtGui/QPixmap';
import { QMovie } from '../../QtGui/QMovie';

describe('QLabel', () => {
    const label = new QLabel();
    afterAll(() => {
        label.close();
    });
    it('instantiate a label instance', () => {
        const label = new QLabel();
        expect(label.inherits('QLabel')).toBe(true);
    });
    it('setText', () => {
        const label = new QLabel();
        label.setText('hello');
        expect(label.text()).toEqual('hello');
    });
    it('setWordWrap', () => {
        const label = new QLabel();
        label.setWordWrap(true);
        expect(label.wordWrap()).toEqual(true);
        label.setWordWrap(false);
        expect(label.wordWrap()).toEqual(false);
    });
    it('setPixmap', () => {
        const label = new QLabel();
        const pixMap = new QPixmap();
        label.setPixmap(pixMap);
        expect(label.pixmap()).toEqual(pixMap);
    });
    it('setMovie', () => {
        const label = new QLabel();
        const movie = new QMovie();
        label.setMovie(movie);
        expect(label.movie()).toEqual(movie);
    });
    it('check if signals are working', () => {
        const widget = new QLabel();
        const mock = jest.fn();
        widget.addEventListener('objectNameChanged', mock);
        widget.setObjectName('testName');
        expect(mock).toBeCalledWith('testName');
        expect(mock).toBeCalledTimes(1);
    });
    it('check if signals are working from QWidget', () => {
        const widget = new QLabel();
        const mock = jest.fn();
        widget.addEventListener('windowTitleChanged', mock);
        widget.setWindowTitle('testName');
        expect(mock).toBeCalledWith('testName');
        expect(mock).toBeCalledTimes(1);
    });
});
