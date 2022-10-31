export const getColorByType = (type) => {
    switch (type) {
        case 'fire':
            return 'is-danger';
        case 'water':
            return 'is-info';
        case 'grass':
            return 'is-success';
        case 'electric':
            return 'is-warning';
        case 'flying':
            return 'is-link';
        default:
            return ''
    }
}
