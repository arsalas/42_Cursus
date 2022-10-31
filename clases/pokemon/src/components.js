import { getColorByType } from "./helpers.js";

export const titleComponent = (id, name) =>  `<h3 class="title">#${id} - ${name.toUpperCase()}</h3>`;

export const statsComponent = (stats) => {
    let html = `<div class="mt-5 is-size-5 has-text-weight-bold">STATS</div>`;
    stats.forEach(stat => {
        html += `
        <div class="is-flex is-justify-content-space-between">
            <div class="has-text-weight-bold">${stat.stat.name.toUpperCase()}</div>
            <div class="has-text-weight-bold">${stat.base_stat}</div>
        </div>
        <progress class="progress is-primary is-small" value="${stat.base_stat}" max="255">${stat.base_stat}</progress>
        `
    });
    return html;
}

export const typesComponent = (types) => {
    let html = `<div class="mt-5 is-size-5 has-text-weight-bold">TYPES</div>`;
    types.forEach(type => {
        html += `<span class="tag ${getColorByType(type.type.name)} is-medium mr-2">${type.type.name.toUpperCase()}</span>`;
    });
    return html;
}

export const imagesComponent = (image, imageShiny, imageBack, imageBackShiny) => {
    let html = `<img src="${image}">`
    html += `<img src="${imageShiny}">`
    html += `<img src="${imageBack}">`
    html += `<img src="${imageBackShiny}">`
    return html
}
