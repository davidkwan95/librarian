let component = ReasonReact.statelessComponent("SearchResult");

let make = (~volumes: VolumeModules.volumes, _children) => {
  ...component,
  render: _self => (
    <div style=(ReactDOMRe.Style.make(~textAlign="center", ()))>
    (
      ReasonReact.array(
        Array.of_list(
          List.map(
            (volume: VolumeModules.volume) =>
              <div key=volume.id
                style=(ReactDOMRe.Style.make(
                  ~border="solid 1px",
                  ~padding="20px",
                  ~margin="20px",
                  ()
                ))
              >
                <VolumeCard volume=volume />
              </div>,
            volumes
          ),
        ),
      )
    )
    </div>
  )
}
