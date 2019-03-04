let component = ReasonReact.statelessComponent("SearchResult");

let make = (~volumes: VolumeModules.volumes, _children) => {
  ...component,
  render: _self => (
    <div className="list-group list-group-horizontal row justify-content-center">
      {
        List.map(
          (volume: VolumeModules.volume) => <VolumeCard key=volume.id volume=volume />,
          volumes
        )
        |> Array.of_list
        |> ReasonReact.array
      }
    </div>
  )
}
